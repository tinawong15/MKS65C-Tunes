# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

struct song_node{
  char song[100];
  char artist[100];
  struct song_node *next;
};

// print the entire list
void print_list(struct song_node *node_pointer);

// insert nodes at the front
struct song_node * insert_front(struct song_node *node_pointer, char * song, char * artist);

// insert nodes in order; alphabetical by Artist then by Song
struct song_node * insert_order(struct song_node *node_pointer, char * song, char * artist);

// free the entire list
struct song_node * free_list(struct song_node *node_pointer);

// find and return a pointer to a node based on artist and song name
struct song_node * find_node(struct song_node *node_pointer, char * song, char * artist);

// find and return a pointer to the first song of an artist based on artist name
struct song_node * find_song(struct song_node *node_pointer, char * artist);

// Return a pointer to random element in the list.
struct song_node * random_element(struct song_node *node_pointer);

// remove a single specified node from the list
struct song_node * remove_node(struct song_node *node_pointer, char * song, char * artist);
