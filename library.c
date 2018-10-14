# include "library.h"
# include "list.h"


//helper for finding index based on artist name
int find_index(char * artist){
  int index;
  // extracting the first letter of the artist's name for the library index
  // check for upper case
  if(artist[0] >= 'A' && artist[0] <= 'Z'){
    index = artist[0] - 65;
  }
  // check for lower case
  else if(artist[0] >= 'a' && artist[0] <= 'z'){
    index = artist[0] - 97;
  }
  return index;
}

// Add song nodes.
// struct song_node ** add_node(struct song_node **library, char * song, char * artist){
//   int index = find_index(artist);
//   // printf("%s\n", library[index] -> song);
//   // if first node
//   // printf("index: %d\n", index);
//   if(strcmp(library[index] -> song, "") == 0){
//     struct song_node *new_pointer = malloc(sizeof(struct song_node));
//     strcpy(new_pointer -> song, song);
//     strcpy(new_pointer -> artist, artist);
//     new_pointer -> next = NULL;
//     library[index] = new_pointer;
//     // printf("%s\n", new_pointer -> song);
//     // printf("%s\n", library[index] -> song);
//   }
//   // let insert_order handle the rest
//   else {
//     printf("library[%d]: %s | %s\n", index, library[index] -> artist,library[index] -> song );
//     library[index] = insert_order(library[index] -> next, song, artist);
//   }
//   return library;
// }

// temp
struct song_node ** add_node(struct song_node **library, char * song, char * artist){
  int index = find_index(artist);
  library[index] = insert_order(library[index], song, artist);
  return library;
}

// Search for a song given song and artist name (return a pointer).
struct song_node * search_song(struct song_node **library, char * song, char * artist){
  int index = find_index(artist);
  if(strcmp(song, "") || strcmp(artist, "")) {
    return NULL;
  }
  return find_node(library[index], song, artist);
}

// Search for an artist.
// struct song_node * search_artist(struct song_node **library, char * artist){
//   int index = find_index(artist);
//   if(strcmp(artist, "")) {
//     return NULL;
//   }
//   return find_song(library[index], artist);
// }


// Print out the entire library.
void print_library(struct song_node **library){
  char letter = 'a';
  int index;
  for (index = 0; index < 27; index++){
    printf("%c: ", letter);
    print_list(library[index]);
    letter++;
  }
}

// Print out all the songs of a certain artist
void print_artist(struct song_node **library, char * artist){
  int index = find_index(artist);
  struct song_node * list = library[index];
  // iterate through the linked list and print everything
  while (list){
    if (strcmp(list -> artist, artist) == 0){
      printf("%s: %s -> ", list -> artist, list -> song);
    }
    list = list -> next;
  }
  printf("END \n");
}

// Print out all the entries under a certain letter.
void print_letter_list(struct song_node **library, char letter){
  int index = find_index(&letter);
  printf("%c: ", letter);
  print_list(library[index]);
}


//
//
//
// // Shuffle - print out a series of randomly chosen songs.
// void shuffle_print(struct song_node **library){
//
// }
//
// // Delete a song
// struct song_node ** delete_song(struct song_node **library){
//
// }
//
// // Clear the library.
// struct song_node ** clear_library(struct song_node **library){
//
// }
