#ifndef _CHECKERBOARD_H
#define _CHECKERBOARD_H

/***********************MACRO DEFINITION**************************/
#define _STATUS int
#define _TRUE 1
#define _FALSE 0
//macro definition to describe the status of some function
/*****************************************************************/


#include<iostream>
#include<vector>
#include<string>


/**this class to describe the checkerboard*/
class CcheckerBoard{
	public:
		CcheckerBoard();
		//this is the constructor which is used to initialize the member value;
		//the size of the checkerboard's defalut value is 15*15
		
		CcheckerBoard(int isize);
		//this is the constructor which is used to initialize thr member value;
		//the isize is to set the size of the checkerboard's value is isize*isize;

		std::string m_fnTrans(int n) const;
		//this function is to translate the int which is from the member value m_boardVal to char; 
		//the int n is intiger from m_boardVal;

		void m_fnBoardShow() const;
		//this function is to show the checkerboard based on the member value(m_boardVal);
                
	       	_STATUS m_insertWchess(int x,int y) ;
		//this function is to insert the white chess in the CcheckerBoard;
		 
	        _STATUS m_insertBchess(int x,int y) ;	
                //this function is to insert the biack  chess in the CcheckerBoard; 

	protected:
		std::vector<std::vector<int>> m_boardVal;
		//the vector describe a array which is 2 dimention;
		//the vector will be initialized in the constructor; 

};
/******************************************/


















#endif
