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
  else{
    return -1;
  }
  return index;
}

// Add song nodes.
struct song_node ** add_node(struct song_node **library, char * song, char * artist){
  int index = find_index(artist);
  // print_list(library[index]);
  if (index != -1){
    library[index] = insert_order(library[index], song, artist);
  }
  return library;
}

// Search for a song given song and artist name (return a pointer).
struct song_node * search_song(struct song_node **library, char * song, char * artist){
  int index = find_index(artist);
  if (index != -1) {
    return find_node(library[index], song, artist);
  }
  return NULL;
}

//Search for an artist.
struct song_node * search_artist(struct song_node **library, char * artist){
  int index = find_index(artist);
  if (index != -1) {
    return find_song(library[index], artist);
  }
  return NULL;
}

// Delete a song
struct song_node ** delete_song(struct song_node **library, char * song, char * artist){
  int index = find_index(artist);
  if (index != -1){
    library[index] = remove_node(library[index], song, artist);
  }
  return library;
}

// Shuffle - print out a series of randomly chosen songs.
void shuffle_print(struct song_node **library, int times){
  int song_amount;
  int index;
  struct song_node *chosen_song;
  for(song_amount = 0; song_amount < times; song_amount++) {
    index = rand() % 27;
    while(library[index] == NULL) {
      index = rand() % 27;
    }
    chosen_song = random_element(library[index]);
    printf("Song #%d: %s by %s\n ", song_amount+1, chosen_song -> song, chosen_song -> artist);
  }
}


// Print out the entire library.
void print_library(struct song_node **library){
  char letter = 'a';
  int index;
  for (index = 0; index < 27; index++){
    printf("%c| ", letter);
    print_list(library[index]); //skip the empty node
    letter++;
  }
}

// Print out all the songs of a certain artist
void print_artist(struct song_node **library, char * artist){
  int index = find_index(artist);
  if (index != -1){
    //skip the first node, which is an empty node
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
}

// Print out all the entries under a certain letter.
void print_letter_list(struct song_node **library, char letter){
  int index = find_index(&letter);
  if (index != -1){
    printf("%c: ", letter);
    print_list(library[index] -> next); //skip the empty node
  }
}

// // Clear the library.
// struct song_node ** clear_library(struct song_node **library){
//
// }
