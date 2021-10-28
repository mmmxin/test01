#ifndef _PERSON_H
#define _PERSON_H
#include"checkerboard.h"

/***************Macro definition***********************/
#define DIRECTION 	int
#define VERTICAL 	1
#define HORIZON  	2
#define FSLASH		3	//forward slash
#define BSLASH		4	//back slash

#define PLAYERTYPE      int
#define BLACK		0
#define WHITE		1
#define NOWINGER	-1
/*****************************************************/
//
//
//
/*********************abstract class Cpeople*****************************/
class Cpeople{
	public:
		Cpeople(int iId);
		//This is the constructor;
		//main job is to initialize m_peopleID;

		_STATUS m_fnEye(Ccheckerboard myBoard,int x_label,int y_label,int& evalue) const;
	        //to imitate the eye of people to see the board;
		//input an object of the class(Ccheckerboard) which is the checkerboard need to be seen;
		//input the x_label and y_label of the checkerboard;
		//the evalue need te be read is the value of the vector of the member of the object of the Ccheckerboard;

		virtual _STATUS m_fnHand(Ccheckerboard myBoard,int x_label,int y_label,int hvalue) = 0;
		//to imitate the hand of people to play the game;
		//input an object of the class(Ccheckerboard) which is the checkerboard need to be writed;
		//input the x_label and y_label of the checkerboard;
		//input hvalue need te be write to the value of the vector of the member of the object of the Ccheckerboard;
		//this is a pure virtual function becasue of the different of the judge and the player;
		

		_STATUS m_fnConsiCount(Ccheckerboard myBoard,int x_label,int y_label,DIRECTION mscroDir,int& numOfCount);
		//to count the number of the piece of the location(depend on the x_label and the y_label) of the checkerboard;
		//input an object of the class(Ccheckerboard) which is the checkerboard need to be count;
		//input the x_label and y_label of the checkerboard;
		//input the DIRECTION is to descrebe the direction;
		//the numOfCount which we need is the number of the piece in that direction;

	protected:
		int m_peopleId;
		//the identifier of each player;

};

/************************************************************************/
//
//
//
/**************************class Cplayer*********************************/
class Cplayer:public Cpeople{
	public:
		Cplayer(PLATERTYPE playerType);
		//This is the constructor;
		//main job is to initialize the m_playerType;
		
		virtual  _STATUS m_fnHand(Ccheckerboard myBoard,int x_label,int y_label,int hvalue);
		//the virtual function inherit from base class;
		//to imitate the hand of people to play the game;
		//input an object of the class(Ccheckerboard) which is the checkerboard need to be writed;
		//input the x_label and y_label of the checkerboard;
		//input hvalue need te be write to the value of the vector of the member of the object of the Ccheckerboard;




		//there still have some function which doesnt write yet;



		
	protected:
		PLAYERTYPE m_playerType;
		//which color of the piece the player hold;
};
/************************************************************************/
//
//
//
/************************class Cjudge************************************/
class Cjudge:public Cjudge{
	public:
		Cjudge();
		//This is the constructor;
                //main job is to invoke the constructor of the father class;

		virtual  _STATUS m_fnHand(Ccheckerboard myBoard,int x_label,int y_label,int hvalue);
		//the virtual function inherit from base class;
		//do nothing;
		
		PLAYERTYPE m_fnJudgeOutcome(Ccheckerboard myBoard,int x_label,int y_label);
		//base on the lacation(int x_label,int y_label) of thr checkerboard(Ccheckerboard myBoard);
		//to judge whether there generate the winger;
		//if there generate the winger return the type of winger;
		//else return nowinger;
		





		//there still have some function which doesnt write yet;
		
		

};




/************************************************************************/




































#endif
