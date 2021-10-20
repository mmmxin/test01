#include"checkerboard.h"
using namespace std;

//**********the member function of the class Ccheckerboard**********
//
//
//
CcheckerBoard::CcheckerBoard()
{
//this is the constructor which is used to initialize the member value;
//the size of the checkerboard's defalut value is 15*15;
	
	/*to initialize the vector of each line**/
	std::vector<int> line0 = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,2};
	std::vector<int> line1 = {3,4,4,4,4,4,4,4,4,4,4,4,4,4,5};
	std::vector<int> line2 = {6,7,7,7,7,7,7,7,7,7,7,7,7,7,8};
	//line0 stand for the first line;
	//line1 stand for the all line except the first line and the last line;
	//line2 stand for the last line;
	
	/*to initialize the member value m_boardVal**/
	m_boardVal.push_back(line0);
	//fill the first line;
	for(int i = 0; i<13; i++)
		m_boardVal.push_back(line1);
	//fill the middle line;
	m_boardVal.push_back(line2);
	//fill the last line;
		
}
//
//
//
CcheckerBoard::CcheckerBoard(int isize)
{
//this is the constructor which is used to initialize thr member value;
//the isize is to set the size of the checkerboard's value is isize*isize;

	/*to initialize the vector of each line**/
	//
	std::vector<int> line0 = {0};
	//fill the first elem;
	for(int i = 0; i<isize-2; i++)
		line0.push_back(1);
	//fill the middle elem;
	line0.push_back(2);
	//fill the last elem;
	//line0 stand for the first line;
	//
	std::vector<int> line1 = {3};
	//fill the first elem;
	for(int i = 0; i<isize-2; i++)
		line1.push_back(4);
	//fill the middle elem;
	line1.push_back(5);
	//fill the last elem;
	//line1 stand for the middle line;
	//
	std::vector<int> line2 = {6};
	//fill the first elem;
	for(int i = 0; i<isize-2; i++)
		line2.push_back(7);
	//fill the middle elem;
	line2.push_back(8);
	//fill the last elem;
	//line2 stand for the last line;
	/****************************************/

	/*to initialize the member value m_boardVal**/
	m_boardVal.push_back(line0);
	//fill the first line;
	for(int i = 0; i<isize-2; i++)
		m_boardVal.push_back(line1);
	//fill the middle line;
	m_boardVal.push_back(line2);
	//fill the last line;
	/********************************************/	
        
	

}
//
//
//
std::string CcheckerBoard::m_fnTrans(int n) const
{
//this function is to translate the int which is from the member value m_boardVal to char; 
//the int n is intiger from m_boardVal;
	
	if(n==0)
		return "┌";
	else if(n==1)
		return "┬";
	else if(n==2)
		return "┐";
	else if(n==3)
		return "├";
	else if(n==4)
		return "┼";
	else if(n==5)
		return "┤";
	else if(n==6)
		return "└";
	else if(n==7)
		return "┴";
	else if(n==8)
		return "┘";
	else if(n==100)
		return "●";
	else if(n==200)
		return "○";
	else{
		std::cout<<"ERROR -001"<<std::endl;
		return "*";
	}
}
//
//
//
void CcheckerBoard::m_fnBoardShow() const
{
//this function is to show the checkerboard based on the member value(m_boardVal);

	int ilen = m_boardVal.size();
	//to get the size of the member value m_boardVal;
	for(int i = 0; i<ilen; i++)
	{
	//for each line;
		for(int j = 0; j<ilen; j++)
		{
		//for each elem;
			std::cout<<m_fnTrans(m_boardVal[i][j]);
		}
		std::cout<<std::endl;
		//each line need to wrap;
	}
}
//
//
//
_STATUS CcheckerBoard::m_insertWchess(int x,int y) 
{
//this function is to insert white chess in CcheckerBoard(insert posistion:(x,y))
	
	if(x<m_boardVal.size() && y<m_boardVal.size() && x>=0 && y>=0)
    	{
	     	this->m_boardVal[x][y]=200;
		return _TRUE;
     	}else
     	{
     		return _FALSE;
     	}
	//to insert whitechess.if input position of chess isn't right ,will return _FALSE;

}
//
//
//
_STATUS CcheckerBoard::m_insertBchess(int x,int y) 
{
//this function is to insert black chess in CcheckerBoard(insert posistion:(x,y))
   
     	if(x<m_boardVal.size() && y<m_boardVal.size() && x>=0 && y>=0)
     	{
   		this->m_boardVal[x][y]=100;
		return _TRUE;
     	}else
     	{
       		return _FALSE;
     	}	
	//to insert black chess.if input position of chess isn't right ,will return _FALSE;

}

//
//
//
//*****************************************************************
