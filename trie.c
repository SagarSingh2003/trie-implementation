
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TrieNode{
    struct TrieNode* child[26];
    bool is_end_of_word;
};

struct TrieNode* createTrieNode(){
      
      struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
      
      node->is_end_of_word = false;
      
      for(int i = 0 ; i < 26 ; i++){
          node->child[i] = NULL;
      }
      
      return node;
  
}

void insert(const char* c , struct TrieNode* root_node){
      
      struct TrieNode* curr = root_node;
      
      while(*c){
        
          int index = *c - 'a';
        
          if(curr->child[index] != NULL){
            
            
            curr = curr->child[index];
            
          }else{
              curr->child[index] = createTrieNode();
              curr = curr->child[index];
          }
          
          c++;    
      }
      
      curr->is_end_of_word = true;

}

bool search(const char* c , struct TrieNode* root_node){
    
    struct TrieNode* curr = root_node;
    
    while(*c){
        
        int index = *c - 'a';
        
        if(curr->child[index] != NULL ){
          
            curr = curr->child[index];
            c++;
          
        }else{
          
          return false;
        
          
        }
                
    }    
    
    
    return curr->is_end_of_word;
      
}

int main(){
  
  struct TrieNode* root = createTrieNode();
  
  insert("sagar" , root);
  insert("singh" , root);
  insert("diptilal" , root);
  insert("masadur" , root);
  
  
  printf("search for word ragas, expected answer false : %B\n", search("sagar" , root));
  printf("search for word diptilal, expected answer true : %d\n", search("diptilal" , root ));
  
  
}