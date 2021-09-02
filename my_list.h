// *** ADDED BY HEADER FIXUP ***
#include <iterator>
// *** END ***
 #ifndef _list_h_
 #define _list_h_


typedef struct LIST {
 #if defined(__cplusplus) && __cplusplus >= 201103L
   struct LIST *prev{nullptr}, *next{nullptr};
   void *data{nullptr};
 #else
   struct LIST *prev, *next;
   void *data;
 #endif
 } LIST;

 typedef int (*list_walk_action)(void *, void *);

 extern LIST *list_add(LIST *root, LIST *element);
 extern LIST *list_delete(LIST *root, LIST *element);
 extern LIST *list_cons(void *data, LIST *root);
 extern LIST *list_reverse(LIST *root);
 extern void list_free(LIST *root, unsigned int free_data);
 extern unsigned int list_length(LIST *);
 extern int list_walk(LIST *, list_walk_action action, unsigned char *argument);

 #define list_rest(a) ((a)->next)

 #endif

