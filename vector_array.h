

struct _vector_array
{
	void **array;
	int used;
	int allocated;
	void (*dispose_item) (void *item);
};


struct _vector_array *_vector_array_new( void (*dispose_item) (void *item) );
bool _vector_array_resize(struct _vector_array *c);
void _vector_array_erase(struct _vector_array *c,  void  **i );
void _vector_array_clear(struct _vector_array *c );
void **_vector_array_push_back(struct _vector_array *c,  void  *i );
bool _vector_array_delete(struct _vector_array *c);

