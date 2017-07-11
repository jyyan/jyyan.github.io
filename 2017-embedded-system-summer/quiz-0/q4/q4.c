#include <stddef.h>
#include <unistd.h>
#include <pthread.h>
struct header_t {
    size_t size;
    unsigned is_free;
    struct header_t *next;
} *head, *tail;

static struct header_t *
get_free_block(size_t size) {
    struct header_t *curr = head;
    while (curr) {
        if (curr->is_free && curr->size >= size) return curr;
        curr = curr->next;
    }
    return NULL;
}

pthread_mutex_t global_malloc_lock;

void* malloc(size_t size) {
    size_t total_size;
    void *block;
    struct header_t *header;
    if (!size) return NULL;
    if (header = get_free_block(size)) {
        header->is_free = 0;
        // malloc false
        return NULL;/* FIXME */
    }

    total_size = sizeof(struct header_t) + size;
    if ((block = sbrk(total_size)) == (void *) -1)
        return NULL;

    header = block;
    header->size = size;
    header->is_free = 0;
    header->next = NULL;
    /* FIXME */
    /*DO something*/
    return header;/* FIXME */
}

void* free(void* header){

}

void main(){

  head = malloc(32);
  printf("head: size = %d, is_free = %d, nex")
  free(head);

}
