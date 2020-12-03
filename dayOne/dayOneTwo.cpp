#include <iostream>
#include <fstream>
#include <memory>
using namespace std;


class Node {
public:
	int data;
	Node* prev;
	Node* next;
};

class list {
	private:
	public:
	Node* head;
	Node* tail;
	list(){
		head = NULL;
		tail = NULL;
	}
};

int main(){
	ifstream input;
	input.open("../../../input.txt");
	if(!input){
		cerr << "Cannot open input file." << endl;
		return 0;
	}

	list nums = list(); 
	string strNumber;
	while(getline(input, strNumber)){
		int number = std::stoi(strNumber);
		if(nums.head == NULL){
			cout << "So no head??" << endl;
			cout << number << endl;
			
			Node* temp = new Node;
			temp->data = number;
			nums.head = temp;
			nums.tail = temp;
		}
		else{
			if(number < nums.head->data){
				cout << number << endl;
				Node* temp = new Node;
				temp->data = number;

				temp->next = nums.head;
				temp->next->prev = temp;
				nums.head = temp;
			}
			else{
				cout << number << endl;
				Node* iter = nums.head;
				while(number > iter->data && iter->next != NULL){
					iter = iter->next;
				}
				
				cout << "Current iter = " << iter->data << endl;
				cout << "Current num = " << number << endl;
				Node* temp = new Node;
				temp->data = number;
				
				if(iter->next == NULL){
					if(iter->data < number){
						iter->next = temp;
						temp->prev = iter;
						temp->next = NULL;
						nums.tail = temp;
					}
					else{
						temp->next = iter;
						temp->prev = iter->prev;
						
						temp->prev->next = temp;
						temp->next->prev = temp;
					}
				}
				else{
					temp->next = iter;
					temp->prev = iter->prev;
					
					temp->prev->next = temp;
					temp->next->prev = temp;
				}
			}
		}

	}

	cout << "DONE!!" << endl;
	Node* iterate = nums.head;
	int found = 0;
	while(iterate != NULL){
		Node* adder = iterate->next;
		Node* adder2 = nums.tail;
		while(iterate->data + adder->data + adder2->data != 2020 && adder->next != NULL){
			adder = adder->next;
			adder2 = nums.tail;
			while(iterate->data + adder->data + adder2->data != 2020 && adder2->prev != NULL){
				adder2 = adder2->prev;
			}
		}
		
		if(iterate->data + adder->data + adder2->data == 2020){
			cout <<"Found 3 nums:" << endl;
			cout << iterate->data << ", " << adder->data << ", " << adder2->data << endl;
			cout << "Multiply = " << iterate->data * adder->data * adder2->data << endl;
			break;
		}
		iterate = iterate->next;
	}
	
	iterate = nums.head;
	Node* iterate2 = nums.head;
	while(iterate->next != NULL){
		iterate2 = iterate->next;
		free(iterate);
		iterate = iterate2;
	}
	return 0;
}

