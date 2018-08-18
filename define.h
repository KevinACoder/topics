#ifndef TOPICS_DEFINE
#define TOPICS_DEFINE

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <time.h>
#include <limits.h>
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::vector;

//data structure
typedef double val_type;
typedef std::vector<val_type> ARR_1D_F;
struct sl_node //singal linked-list node 
{
	val_type  _val;
	sl_node   *_next;

	sl_node(val_type val):_val(val),_next(nullptr){}
};

struct dl_node //double linked-list node
{
	val_type  _val;
	dl_node   *_prev;
	dl_node   *_next;

	dl_node(val_type val):_val(val),_prev(nullptr),_next(nullptr){}
};

struct bst_node
{
	val_type	_val;
	bst_node	*_left;
	bst_node	*_right;

	bst_node(val_type val):_val(val),_left(nullptr),_right(nullptr){}
};

//algorithm
// ...sort
void cocktail_sort(val_type*& arr, const int len);
void bucket_sort(val_type*& arr, const int n);
string frequency_sort(string str);
void merge(val_type*& arr, int low, int middle, int up);
void merge_sort(val_type*& arr, int low, int up);
bst_node* insert_bst(bst_node *root, val_type key);
void inorder_visit(bst_node *root, val_type*& arr, int& ix);
void bst_sort(val_type*& arr, const int len);

void sort_demo();

// ...linked list
void linked_list_demo();
sl_node *sorted_insert(sl_node *head, val_type data);
void print_list(sl_node *head);
sl_node *del_by_key(sl_node *head, val_type key);
sl_node *del_by_pos(sl_node *head, int pos);
int get_length(sl_node *head);
int get_length_recursive(sl_node *head);
void del_list(sl_node **head_ref);
bool search_list_recursive(sl_node *head, val_type key);
sl_node *get_the_nth_node(sl_node *head, int n);
sl_node *get_the_nth_node_from_tail(sl_node *head, int n);

#endif