#include <dmc_unrar.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <archive.rar>\n", argv[0]);
    return 1;
  }

  const char *archive_path = argv[1];
  dmc_unrar_archive archive;

  // Initialize the archive structure
  if (dmc_unrar_archive_init(&archive) != DMC_UNRAR_OK) {
    printf("Failed to initialize archive structure.\n");
    return 1;
  }

  printf("Opening archive %s ...\n", archive_path);
  if (dmc_unrar_archive_open_path(&archive, archive_path) != DMC_UNRAR_OK) {
    printf("Failed to open archive: %s\n", archive_path);
    return 1;
  }

  printf("Contents of archive: %s\n", archive_path);
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

    printf("- %s (Size: %llu bytes)\n", filename, file_stat->uncompressed_size);
  }

  dmc_unrar_archive_close(&archive);
  return 0;
}
