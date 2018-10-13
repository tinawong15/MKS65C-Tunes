struct song_node * library[27];

// Add song nodes.
struct song_node * add_node(struct song_node *library);

// Search for a song given song and artist name (return a pointer).
struct song_node * search_song(struct song_node *library, char * song, char * artist);

// Search for an artist.
struct song_node * search_artist(struct song_node *library, char * artist);

// Print out all the entries under a certain letter.
struct song_node * print_letter_list(struct song_node *library, char letter);

// Print out all the songs of a certain artist
void print_artist(struct song_node *library);

// Print out the entire library.
void print_library(struct song_node *library);

// Shuffle - print out a series of randomly chosen songs.
void shuffle_print(struct song_node *library);

// Delete a song
struct song_node * delete_song(struct song_node *library);

// Clear the library.
struct song_node * clear_library(struct song_node *library);
