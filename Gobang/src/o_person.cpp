#include"person.h"


/****************check function*********************/
//
//
//
/**to check if the num over the limits*/
_STATUS fnCheckLimits(int num,int limits){
	if(num>=0&&num<limits)
		return _TRUE;
	else
		return _FALSE;
}


/**************************************************/





/*********************class Cpeople*******************/
//
//
//
/**This is the constructor;
 * main job is to initialize m_peopleId;*/
Cpeople::Cpeople(int iId):m_peopleId(iId){};
//
//
//
/**to imitate the hand of people to play the game;
 * input an object of the class(Ccheckerboard) which is the checkerboard need to be writed;
 * input the x_label and y_label of the checkerboard;
 * the evalue need te be read is the value of the vector of the member of the object of the Ccheckerboard;*/
_STATUS m_fnEye(CcheckerBoard myBoard,int x_label,int y_label,int& evalue) const{
	int len = myBoard.m_boardVal.size();//to get the size of the vector(it is the dimention of the checkerboard)
	
	if(fnCheckLimits(x_label,len)==_FALSE||fnCheckLimits(y_label,len)==_FALSE)//whether the x_label or the y_label over the limits;
		return _FALSE;
	
	int res = myBoard.m_fnReadChess(x_label,y_label,evalue);//check and get the value from the checkerboard;
	if(res == _FALSE)
		return _FALSE;
	else
		return _TURE;
	
}
//
//
//
/**to count the number of the piece of the location(depend on the x_label and the y_label) of the checkerboard;
 *input an object of the class(Ccheckerboard) which is the checkerboard need to be count;
 *input the x_label and y_label of the checkerboard;
 *input the DIRECTION is to descrebe the direction;
 *the numOfCount which we need is the number of the piece in that direction;*/
_STATUS m_fnConsiCount(CcheckerBoard myBoard,int x_label,int y_label,DIRECTION mscroDir,PLAYERTYPE color,int& numOfCount){
	int x_change,y_change;//change step size;
	int value;//to read the value;
	int x_temp;//temp;
	int y_temp;//temp;
	int len = myBoard.m_boardVal.size();//to get the size of the vector(it is the dimention of the checkerboard)
	
	numOfCount = 0;//initialize the value;

	/**set the step size based on the direction*/
	if(mscroDir == VERTICAL){
		x_change = 0;
		y_change = 1;
	}else if(mscroDir == HORIZON){
		x_change = 1;
		y_change = 0;
	}else if(mscroDir == FSLASH){
		x_change = 1;
		y_change = 1;
	}else if(mscroDir == BSLASH){
		x_change = -1;
		y_change = 1;
	}else;

	/**check whether input error*/
	if(color == EMPTY)
		return _FALSE;

	/**count the num in forward*/
	x_temp = x_label+x_change;//first step
	y_temp = y_label+y_change;
	while(myBoard.m_fnReadChess(x_temp,y_temp,value) == _TRUE){
		if(value != color;)
			break;

		numOfCount++;
		x_temp = x_temp+x_change;//next step;
		y_temp = y_temp+y_change;
	}
	/**count the num in back*/
	x_temp = x_label-x_change;//first step
        y_temp = y_label-y_change;
        while(myBoard.m_fnReadChess(x_temp,y_temp,value) == _TRUE){
                if(value != color;)
			break;

		numOfCount++;
                x_temp = x_temp-x_change;//next step;
                y_temp = y_temp-y_change;
        }
	return _TRUE;
}

/************************************************************************/





/**************************class Cplayer*********************************/

/**This is the constructor;
  *main job is to initialize the m_playerType;*/
Cplayer::Cplayer(PLATERTYPE playerType,int iId):Cpeople(int iId),m_playerType(playerType){};
//
//
//
/*to imitate the hand of people to play the game;
input an object of the class(Ccheckerboard) which is the checkerboard need to be writed;
input the x_label and y_label of the checkerboard;
input hvalue need te be write to the value of the vector of the member of the object of the Ccheckerboard;
this is a pure virtual function becasue of the different of the judge and the player;
  */
 virtual _STATUS Cplayer:: M_fnHand(CcheckerBoard myBoard, int x_label ,int y_label );
{
        int len = myBoard.m_boardVal.size();//to get the size of the vector(it is the dimention of the checkerboard)

        if(fnCheckLimits(x_label,len)==_FALSE||fnCheckLimits(y_label,len)==_FALSE)//whether the x_label or the y_label over the limits;
        return _FALSE;
         
	if(this->m_playerType==BLACK)//judge PLATERTYPE of chess player
	{
	int re =myBoard.m_fnInsertBchess(x_label , y_label);
         //insert black chess on the position(x_label ,y_label)
	    return re; 
   
	}else if(this->m_playerType==WHITE)
	{
	int re=myBoard.m_fnInsertWchess(x_label , y_label);
	// insert white chess on the position(x_label,y_label)
	   return re;
        }else return _FALSE;

}

























/*****************************************************/
