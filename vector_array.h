

struct _vector_array
{
	void **array;
	int used;
	int allocated;
};


struct _vector_array *_vector_array_new();
bool _vector_array_resize(struct _vector_array *c);
void _vector_array_erase(struct _vector_array *c,  void  **i, void (*fn) (void *item) );
void **_vector_array_push_back(struct _vector_array *c,  void  *i );
bool _vector_array_delete(struct _vector_array *c);

