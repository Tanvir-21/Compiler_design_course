//
//  main.cpp
//  lexical_analyzer
//
//  Created by MD Tanvir Anjum on 9/2/21.
//  Copyright © 2021 Smart Lab. All rights reserved.
//

#include<iostream>
#include <fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isKeyword(char buffer[]){
    char keywords[32][10] =
    {
        "auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union",
        "unsigned","void","volatile","while"
    };
    int i, flag = 0;
    for(i=0; i<32; i++){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
    
    char ch, buffer[15], logical_operator[] = "><", math_operator[]= "+-*/=", other[] = ",;\(){}[]'':", number[] = ".0123456789";
    
    ifstream fin("/Users/tanvir/Desktop/Demo_app/lexical_analyzer/input.txt");
    int i, j = 0; //iterators
    
    if(!fin.is_open()){
        cout<<"Error while opening the file\n";
        exit(0);
    }
    
    while (!fin.eof()) {
        ch = fin.get();
        
        for(i=0; i<2; i++){
            if (ch == logical_operator[i])
                cout<<ch<<" is logical operator\n";
        }
        
        for(i=0; i<5; i++){
            if (ch == math_operator[i])
                cout<<ch<<" is math operator\n";
        }
        
        for(i=0; i<12; i++){
            if (ch == other[i])
                cout<<ch<<" other operator\n";
        }
        for(i=0; i<12; i++){
            if (ch == number[i])
                cout<<ch<<" Numerical value\n";
        }
        
        if(isalnum(ch)){
            buffer[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n' ) && (j != 0)){
            buffer[j] = '\0';
            j = 0;
            if(isKeyword(buffer) == 1)
                cout<<buffer<<" is keyword\n";
            else
                cout<<buffer<<" is indentifier\n";
        }
    }
    
    fin.close();
    
    return 0;
    
}
