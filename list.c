#include "list.h"

// insert nodes at the front
struct song_node * insert_front(struct song_node *node_pointer, char * song, char * artist){
  // initialize new node
  struct song_node *new_start_pointer = malloc(sizeof(struct song_node));
  strcpy(new_start_pointer -> song, song);
  strcpy(new_start_pointer -> artist, artist);
  new_start_pointer -> next = node_pointer;
  return new_start_pointer;
}

// insert nodes in order; alphabetical by Artist then by Song
struct song_node * insert_order(struct song_node *node_pointer, char * song, char * artist){
  // initialize new node
  struct song_node *new_pointer = malloc(sizeof(struct song_node));
  strcpy(new_pointer -> song, song);
  strcpy(new_pointer -> artist, artist);
  new_pointer -> next = NULL;

  // if node_pointer is NULL, then just return new_pointer
  if (node_pointer == NULL){
    return new_pointer;
  }

  struct song_node *current_pointer = node_pointer;   // create an alias to the list
  struct song_node *previous_pointer; //points to the node previous to the curr ptr
  previous_pointer = current_pointer;
  // average case
  while (current_pointer -> next != NULL){
    // compare artists first
    //printf("Difference b/t %s and %s: %d\n", new_pointer -> artist, current_pointer -> artist, strcmp(new_pointer -> artist, current_pointer -> artist));
    if(strcmp(new_pointer -> artist, current_pointer -> artist) < 0){
      // if the artist is alphabetically first
      if (previous_pointer == current_pointer){
        new_pointer -> next = current_pointer;
        return new_pointer;
      }
      previous_pointer -> next = new_pointer;
      new_pointer -> next = current_pointer;
      break;
    }
    // if artists match, compare the song titles
    else if(strcmp(new_pointer -> artist, current_pointer -> artist) == 0){
      if(strcmp(new_pointer -> song, current_pointer -> song) < 0){
        if (previous_pointer == current_pointer){
          new_pointer -> next = current_pointer;
          return new_pointer;
        }
        previous_pointer -> next = new_pointer;
        new_pointer -> next = current_pointer;
        break;
      }
    }
    previous_pointer = current_pointer;
    current_pointer = current_pointer -> next;
  }
  // account for when current pointer is alphabetically second last
  if(strcmp(new_pointer -> artist, current_pointer -> artist) < 0){
    previous_pointer -> next = new_pointer;
    new_pointer -> next = current_pointer;
  }
  // account for when the artist name is the same
  else if(strcmp(new_pointer -> artist, current_pointer -> artist) == 0){
    // account for when the new node comes before
    if(strcmp(new_pointer -> song, current_pointer -> song) < 0){
      previous_pointer -> next = new_pointer;
      new_pointer -> next = current_pointer;
    }
    // account for when the new node comes after (between the curr node and the end of the list)
    else {
      current_pointer -> next = new_pointer;
    }
  }
  // account for when current pointer is alphabetically last
  else if(!(current_pointer -> next)) {
    current_pointer -> next = new_pointer;
  }
  // you're returning the original list with the new node appended
  //printf("\nNew Artist: %s New Song: %s Current Artist: %s Current Song: %s Previous Artist: %s Previous Song: %s\n\n", new_pointer -> artist, new_pointer -> song, current_pointer -> artist, current_pointer -> song, previous_pointer -> artist, previous_pointer -> song);
  return node_pointer;
}

// find and return a pointer to a node based on artist and song name
struct song_node * find_node(struct song_node *node_pointer, char * song, char * artist){
  if(strcmp(song, "") == 0 || strcmp(artist, "") == 0) {
    return NULL;
  }
  struct song_node *current_pointer = node_pointer;
  while (current_pointer){
    if(strcmp(current_pointer -> song, song) == 0 && strcmp(current_pointer -> artist, artist) == 0) {
      return current_pointer;
    }
    current_pointer = current_pointer -> next;
  }
  return NULL;
}

// find and return a pointer to the first song of an artist based on artist name
struct song_node * find_song(struct song_node *node_pointer, char * artist) {
  if(strcmp(artist, "") == 0) {
    return NULL;
  }
  struct song_node *current_pointer = node_pointer;
  while (current_pointer){
    if(strcmp(current_pointer -> artist, artist) == 0) {
      return current_pointer;
    }
    current_pointer = current_pointer -> next;
  }
  return NULL;
}

// helper function
int length(struct song_node *node_pointer) {
  struct song_node *current_pointer = node_pointer;
  int count = 0;
  while(current_pointer) {
    count++;
    current_pointer = current_pointer -> next;
  }
  return count;
}

// Return a pointer to random element in the list.
struct song_node * random_element(struct song_node *node_pointer) {
  struct song_node *current_pointer = node_pointer;
  int random_index = rand() % length(node_pointer);
  int num;
  while(current_pointer && num < random_index) {
    //printf("num %d: %s\n", num, current_pointer -> artist);
    current_pointer = current_pointer -> next;
    num++;
  }
  return current_pointer;
}

// remove a single specified node from the list
struct song_node * remove_node(struct song_node *node_pointer, char * song, char * artist){
  struct song_node *current_pointer = node_pointer;
  struct song_node *previous_pointer; //points to the node previous to the curr ptr
  previous_pointer = NULL;
  while (current_pointer){
    // search for a matching node
    if(strcmp(current_pointer -> song, song) == 0 && strcmp(current_pointer -> artist, artist) == 0) {
      // if the first node is being removed
      if (previous_pointer == NULL) {
        free(current_pointer);
        return node_pointer -> next;
      }
      // if the last node is being removed
      if (!current_pointer -> next){
        previous_pointer -> next = NULL;
        free(current_pointer);
        return node_pointer;
      }
      // general case
      previous_pointer -> next = current_pointer -> next;
      free(current_pointer);
      return node_pointer;
    }
    previous_pointer = current_pointer;
    current_pointer = current_pointer -> next;
  }
  return NULL;
}

// print the entire list
void print_list(struct song_node *node_pointer) {
  struct song_node *current_pointer = node_pointer;
  // iterate through the linked list and print everything
  while (current_pointer){
    printf("%s: %s -> ", current_pointer -> artist, current_pointer -> song);
    current_pointer = current_pointer -> next;
  }
  printf("END \n");
}



// SHELVING FREE BECAUSE VALGRIND IS BUGGING OUT
// // free the entire list
// struct song_node * free_list(struct song_node *node_pointer){
//   struct node *current_pointer = node_pointer;
//   struct node *placeholder = node_pointer;
//   while (current_pointer){
//     current_pointer = current_pointer -> next;
//     free(placeholder);
//     placeholder = current_pointer;
//   }
//   return current_pointer;
// }
