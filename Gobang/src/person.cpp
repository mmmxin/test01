#include"person.h"

//**********the member function of the class Cpeople and class Cplayer**********
//
//
//
Cpeople::Cpeople(int iId)
{
  m_peopleId = iId;

}
//
//
//
_STATUS Cpeople::m_fnEye(CcheckerBoard myBoard ,int x_label,int y_label, int evalue)
{
        int isok=myBoard.m_fnReadChess(x_label , y_label , evalue);
         if(isok)
          {
           return _TURE;
          }else
          {
            return _FALSE;
          }
   
}




Cplayer::Cplayer(PLAYERTYPE playerType)
{
//this is the constructor which is used to initialize the m_ playerType value;
 m_playerType = playerType;

}
/*****************************************************************/
//
//
//
virtual _STAUS Cplayer::m_fnHand(CcheckerBoard myBoard,int x_label,int y_label, int hvalue)
{
	int isok;
	if(m_playerTyper)
	{
        isok=myBoard.m_fnInsertWChess(x_label , y_label , hvalue);	
	}else
	{
	 isok=myBoard.m_fnInsertBChess(x_label , y_label , hvalue);
	}
           if(isok)
          {
           return _TURE;
          }else
          {
           return _FALSE;
	  }
             

}
