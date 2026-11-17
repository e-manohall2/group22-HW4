#include <iostream>
#include "bowling_frame.h"
#include <random>
#include <cassert>

using namespace std;

std::random_device dev_main;
std::mt19937 rng_main(dev_main());

int current_game_total(Bowling_Frame * first_frame)
{
	Bowling_Frame * temp = first_frame;
	int game_total = 0;
	int temp_total = 0;
	while(temp)
	{
		game_total += temp->frame_score();
		temp = temp->next_frame();
	}
	return game_total;	
}

int main(int argc, char * argv[] )
{
	typedef  Bowling_Frame* Bowling_Frame_Pointer;
	// cout<<argv[1]<<endl;

	if(argc>2){
		cout<<"Too many arguments, passed 1 arg"<<endl;
		return 0;
	}
	else if(argc<2){
		cout<<"Not enough arguments, should have passed 1 arg"<<endl;
		return 0;
	}

	int playerCount=stoi(argv[1]);
	Bowling_Frame_Pointer array[playerCount];
	// Bowling_Frame** ray = new Bowling_Frame*;
	for(int i=0;i<playerCount;i++){
		array[i]=new Bowling_Frame(0);
	} //created first frame

	Bowling_Frame_Pointer current;
	for(int i=0; i<playerCount;i++){
		current = array[i];
		for(int y=1;y<10;y++){
			current->next_frame(new Bowling_Frame(y));
			current->next_frame()->prev_frame(current);
			current=current->next_frame();
		}
	}
	for(int i=0; i<playerCount;i++){
		array[i]->update_scores(); //update scores for each player
	}

	int totalGame=0;
	cout<<"Player count is: "<<playerCount<<endl;
	for(int player=0; player<playerCount;player++){
		totalGame=0;
		Bowling_Frame_Pointer p = array[player];
		for(int turn=0;turn<10;turn++){
			cout<<"Frame "<<turn+1<<":"<<endl;
			cout<<"\tScore 1: "<<p->score1()<<"\n\tScore 2: "<<p->score2()<<endl;
			totalGame+=p->frame_score();
			p=p->next_frame();
		}
		cout<<"Total Game Score for Player "<<player+1<<": "<<totalGame<<endl<<endl;
	}
	// //make frames
	// Bowling_Frame * f1 = new Bowling_Frame(1);
	// Bowling_Frame * f2 = new Bowling_Frame(2);
	// Bowling_Frame * f3 = new Bowling_Frame(3);

	// //link frames together
	// f1->next_frame(f2);

	// f2->next_frame(f3);
	// f2->prev_frame(f1);

	// f3->prev_frame(f2);	

	// //set frame scores	
	// f1->update_scores();
	// f1->update_scores();
	// cout << "Frame 1 Total: " << current_game_total(f1) << endl;

	// f1->update_scores();
	// f1->update_scores();
	// cout << "Frame 1 and 2 Total: " << current_game_total(f1) << endl;


	// f1->update_scores();
	// f1->update_scores();
	// cout << "Frame 1,2,and 3 Total: " << current_game_total(f1) << endl;

	// //print values
	// cout << "Frame " << f1->frame_num() << ": " << endl
	// 	 << " Score 1: " << f1->score1() << endl
	// 	 << " Score 2: " << f1->score2() << endl;

	// cout << "Frame " << f2->frame_num() << ": " << endl
	//      << " Score 1: " << f2->score1() << endl
	// 	 << " Score 2: " << f2->score2() << endl;

	// cout << "Frame " << f3->frame_num() << ": " << endl
	//      << " Score 1: " << f3->score1() << endl
	// 	 << " Score 2: " << f3->score2() << endl;

	// //iterate through linked list and print values
	// Bowling_Frame * traverse = f1;
	
	// while(traverse)
	// {
	// 	cout << "Frame " << traverse->frame_num() << ": " << endl
	// 	 	 << " Score 1: " << traverse->score1() << endl
	// 	 	 << " Score 2: " << traverse->score2() << endl;

	// 	traverse = traverse->next_frame();
	// }

}
