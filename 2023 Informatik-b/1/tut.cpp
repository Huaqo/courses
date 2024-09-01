#include <iostream>

bool isOdd(int num){
	return num%2;
}

int main(){

	std::cout << "Hello Günter" << std::endl;

	int x = 16;

	for(int i = 0; i<x; i++){
		std::cout << "i: " << i;
		if(isOdd(i)){
			std::cout << " ist gerade" << std::endl;
		}
		else{
			std::cout << " ist nicht gerade" << std::endl;
		}
	}
}
