#include <dmc_unrar.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <archive.rar> <file_to_extract>\n", argv[0]);
    return 1;
  }

  const char *archive_path = argv[1];
  const char *file_to_extract = argv[2];

  dmc_unrar_archive archive;

  // Initialize the archive structure
  if (dmc_unrar_archive_init(&archive) != DMC_UNRAR_OK) {
    printf("Failed to initialize archive structure.\n");
    return 1;
  }

  if (dmc_unrar_archive_open_path(&archive, archive_path) != DMC_UNRAR_OK) {
    printf("Failed to open archive: %s\n", archive_path);
    return 1;
  }

  dmc_unrar_size_t file_count = dmc_unrar_get_file_count(&archive);

  for (dmc_unrar_size_t i = 0; i < file_count; i++) {
    const dmc_unrar_file *file_stat = dmc_unrar_get_file_stat(&archive, i);
    if (!file_stat) {
      printf("Failed to get file details for index %llu\n", i);
      continue;
    }

    char filename[256];
    if (dmc_unrar_get_filename(&archive, i, filename, sizeof(filename)) == 0) {
      printf("Failed to retrieve filename for index %llu\n", i);
      continue;
    }

    if (strcmp(filename, file_to_extract) == 0) {
      FILE *output;
      if (fopen_s(&output, filename, "wb") != 0) {
        printf("Failed to create output file: %s\n", filename);
        dmc_unrar_archive_close(&archive);
        return 1;
      }

      dmc_unrar_size_t uncompressed_size;
      if (dmc_unrar_extract_file_to_file(&archive, i, output, &uncompressed_size, true) != DMC_UNRAR_OK) {
        printf("Failed to extract file: %s\n", filename);
        fclose(output);
        dmc_unrar_archive_close(&archive);
        return 1;
      }

      fclose(output);
      printf("Extracted: %s (%llu bytes)\n", filename, uncompressed_size);
      break;
    }
  }

  dmc_unrar_archive_close(&archive);
  return 0;
}
