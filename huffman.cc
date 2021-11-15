#include "huffman.hh"

Huffman::Huffman(){
	for(int i = 0; i < 256; ++i)
		vect[i] = 0;
	vect[256] = 1;	//eof character
}

Huffman::bits_t Huffman::encode(int symbol){
	//build an htree from scratch using the current frequency table
	HForest::HForest hforest;
	for(int symbol = 0; symbol < 256, ++symbol){
		//make a new tree (check my htree tests) with symbol as the key(?)
		hforest.add_tree()
	}
	
	return 6;
}

int Huffman::decode(bool bit){
	return 8;
}
