#include <bits/stdc++.h>
#include <string>

using namespace std; // Using a matrix here. The number of columns and rows can be changed as per choice

#define R 6
#define C 6
int countoftotal = R*C;

bool check_if_bounds (int row, int col)
{
    //1 << col;
    // cout << C;
    if( row < 0 || col < 0 || row > R-1 ||  col> C-1)
    {
        //cout << "here";
        return false;
    }
    return true; 
}

string CounterClock ( int mat[R][C], int row, int col)
{

	string orientation = "";
    int rowN = row - 1;
    int colN = col;
   // int down = row + 1;
    bool up_T = check_if_bounds( rowN, colN);
    //check_if_bounds( down, col);
    if( up_T && (mat[rowN] [colN] == -1) )
    {
        orientation = "up";
        return orientation;
    }

    rowN = row - 1;
    colN= col- 1; 
   // int down = row + 1;
    bool left_up_T = check_if_bounds(  rowN, colN);
    //check_if_bounds( down, col);
    if(  left_up_T && (mat[ rowN] [colN] == -1) )
    {
        orientation = "left_up";
        return orientation;
    }

    rowN = row;
    colN = col -1; 
   // int down = row + 1;
    bool left_T = check_if_bounds(  rowN, colN);
    //check_if_bounds( down, col);
    if(  left_T && (mat[ rowN] [colN] == -1) )
    {
        orientation = "left";
        return orientation;
    }

    rowN = row + 1;
    colN = col - 1; 
   // int down = row + 1;
    bool down_left_T = check_if_bounds(  rowN, colN);
    //check_if_bounds( down, col);
    if(  down_left_T && (mat[ rowN] [colN] == -1) )
    {
        orientation = "down_left";
        return orientation;
    }

    rowN = row;
    colN = col + 1; 
   // int down = row + 1;
    bool down_T = check_if_bounds( rowN,  colN);
    //check_if_bounds( down, col);
    if(  down_T && (mat[rowN] [colN] == -1) )
    {
        orientation = "down";
        return orientation;
    }

    rowN = row + 1;
    colN = col + 1; 
   // int down = row + 1;
    bool down_right_T = check_if_bounds(  rowN,  colN);
    //check_if_bounds( down, col);
    if(  down_right_T && mat[ rowN] [colN] == -1 )
    {
        orientation = "down_right";
        return orientation;
    }

    rowN = row;
    colN = col + 1; 
   // int down = row + 1;
    bool right_T = check_if_bounds(  rowN,  colN);
    //check_if_bounds( down, col);
    if(  right_T && (mat[ rowN] [colN] == -1) )
    {
        orientation = "right";
        return orientation;
    }

    rowN = row - 1;
    colN = col + 1; 
   // cout << colN<<endl;
   // int down = row + 1;
    bool up_right_T = check_if_bounds( rowN, colN);
    //check_if_bounds( down, col);
    if( up_right_T && (mat[ rowN] [colN] == -1) )
    {
        orientation = "up_right";
        return orientation;
    }


}


string Determine_Orientation (int mat[R][C], int row, int col )
{

    string orientation = "";
    int rowN = row - 1;
    int colN = col;
   // int down = row + 1;
    bool up_T = check_if_bounds( rowN, colN);
    //check_if_bounds( down, col);
    if( up_T && (mat[rowN] [colN] == -1) )
    {

        orientation = "up";
        return orientation;
    }

    rowN = row - 1;
    colN = col + 1; 
   // cout << colN<<endl;
   // int down = row + 1;
    bool up_right_T = check_if_bounds( rowN, colN);
    //check_if_bounds( down, col);
    if( up_right_T && (mat[ rowN] [colN] == -1) )
    {
        orientation = "up_right";
        return orientation;
    }


    rowN = row;
    colN = col + 1; 
   // int down = row + 1;
    bool right_T = check_if_bounds(  rowN,  colN);
    //check_if_bounds( down, col);
    if(  right_T && (mat[ rowN] [colN] == -1) )
    {
        orientation = "right";
        return orientation;
    }

    rowN = row + 1;
    colN = col + 1; 
   // int down = row + 1;
    bool down_right_T = check_if_bounds(  rowN,  colN);
    //check_if_bounds( down, col);
    if( down_right_T && mat[ rowN] [colN] == -1 )
    {
        orientation = "down_right";
        return orientation;
    }

    rowN = row;
    colN = col + 1; 
   // int down = row + 1;
    bool down_T = check_if_bounds( rowN,  colN);
    //check_if_bounds( down, col);
    if(  down_T && (mat[rowN] [colN] == -1) )
    {
        orientation = "down";
        return orientation;
    }

     rowN = row + 1;
    colN = col - 1; 
   // int down = row + 1;
    bool down_left_T = check_if_bounds(  rowN, colN);
    //check_if_bounds( down, col);
    if(  down_left_T && (mat[ rowN] [colN] == -1) )
    {
        orientation = "down_left";
        return orientation;
    }

     rowN = row;
    colN = col -1; 
   // int down = row + 1;
    bool left_T = check_if_bounds(  rowN, colN);
    //check_if_bounds( down, col);
    if(  left_T && (mat[ rowN] [colN] == -1) )
    {
        orientation = "left";
        return orientation;
    }

     rowN = row - 1;
    colN= col- 1; 
   // int down = row + 1;
    bool left_up_T = check_if_bounds(  rowN, colN);
    //check_if_bounds( down, col);
    if(  left_up_T && (mat[ rowN] [colN] == -1) )
    {
        orientation = "left_up";
        return orientation;
    }

}

void Go_Down_Path ( int mat[R][C], int &row , int &col, string orientation, int & countoftotal) 
{

    if( orientation == "up_right")
    {
    	cout << "Here"<<endl;

        if(mat[row][col] != -1 && mat[row][col] != -2)
        {
                mat[row+1][col] = -1;
                countoftotal = countoftotal -1;
        }
        row = row+1 ;
        cout<< row;
   		cout << col;


        while (row >0 && col> 0 && row < R && col < C && mat[row-1][col+1] != -2)
   		{
   			row = row -1;
   			col = col +1;
   			mat [row] [col] = -1 ; 
            countoftotal = countoftotal - 1;
   		}
   		cout<< row;
   		cout << col;

   		return;
    }

    if( orientation == "down_right")
    {
        mat [row+1] [col] = -1 ; // traverse the down part first 
        countoftotal = countoftotal - 1;
        row = row +1 ;

        while (row >0 && col> 0 && row < R && col < C && mat[row][col] != -2)
        {

            row = row +1;
            col = co1 +1;
            if(mat[row][col] != -1 && mat[row][col] != -2)
            {
                mat[row][col] = -1;
                countoftotal = countoftotal -1;
            }
        }
        if ( orientation == "down_right")
        {
            col = col + 1; // ending condition
        }

      
    }

    if( orientation == "up")
    {
        mat [row] [col+1] = -1 ; // traverse the down part first 
        countoftotal = countoftotal - 1;
        col = col +1 ;
        cout<< row;
   		cout << col;


        while (row >0 && col> 0 && row < R && col < C && mat[row-1][col] != -1)
   		{
   			row = row -1;
   			mat [row] [col] = -1 ; 

            if(mat[row][col] != -1 && mat[row][col] != -2)
            {
                mat[row][col] = -1;
                countoftotal = countoftotal -1;
            }
   		}
   		cout<< row;
   		cout << col;

   		return;
    }
    //cout<< row;
    //cout << col<<endl;
    if(orientation == "left")
   	{
   		cout <<"here";
   		mat[row -1] [col] = -1;
        countoftotal = countoftotal - 1;
   		row = row -1;
   		cout << row;
   		cout << col<<endl;
   		//return;

   		while (row >0 && col> 0 && row < R && col < C && mat[row][col] != -2)
   		{
   	

    		col = col -1;
    		//mat [row] [col] = -1 ; 
            if(mat[row][col] != -1)
            {
                mat[row][col] = -1;
                countoftotal = countoftotal -1;
            }
            //countoftotal = countoftotal - 1;

       		for ( int r =0 ; r < R ; r++)
            {
                for ( int c =0 ; c < C ; c++)
                {
                    if (mat[r][c]>0 )
                    {
                          cout << " ";
                         cout << mat[r][c];
                    }
                    
                    else
                        cout << mat[r][c];
                }
                cout << endl; 
            }

        	cout<< row;
        	cout<<col<<endl;

    		if( mat[row][col-1] == -2 || mat[row][col-1] == -1)
    		{
    			return;
    		}


       	}
       	return;
   	}

    if( orientation == "down_left")
    {
        int count = 0;

        while (row >0 && col> 0 && row < R && col < C && mat[row][col] != -2)
        {
            
        	cout<< orientation;
        	cout << count;
        	//return;
            if( mat[row+1][col-1] == -1)
            {
            	if(orientation == "down_left" && count == 0)
            	{
            		row = row + 1;
            		col = col -1;
            		return;
            	}
                return;
            }

            if( mat[row+1][col+1] == -2)
            {
            	if(orientation == "down_left" && count == 0)
            	{
            		row = row - 1;
            		return;
            	}
                return;
            }

            row ++;
            col ++;

            cout<< row;
            cout << col<<endl;
            if(mat[row][col] != -1 && mat[row][col] != -2)
            {
                mat[row][col] = -1;
                countoftotal = countoftotal -1;
            }
        }
    }

    if(orientation == "up_left")
    {
        return;
    }

    if(orientation == "down")
    {
        return;
    }

    if(orientation == "right")
    {
        return;
    }
}


void print( int mat[R][C]) 
{
    for ( int r =0 ; r < R ; r++)
    {
        for ( int c =0 ; c < C ; c++)
        {
            if (mat[r][c]>0 )
            {
                cout << " ";
                 cout <<  mat[r][c];
            }
            
            else
                cout << mat[r][c];
        }
        cout << endl; 
    }



}

void helper(int & c)
{
    c = c + 1;
}

void findTotal(int mat[R][C], int & countoftotal )
{
    for ( int r =0 ; r < R ; r++)
    {
        for ( int c =0 ; c < C ; c++)
        {
            if (mat[r][c] == -2 || mat[r][c] == -1 )
            {
                 countoftotal -- ;
            }
            
        }
    }

}

void populateLast (int mat[R][C])
{
    for ( int r =0 ; r < R ; r++)
    {
        for ( int c =0 ; c < C ; c++)
        {
            if (mat[r][c] == 1 )
            {
                 mat[r][c] = -1;
                 cout<<"last spot poulated";
            }
            
        }
    }
}

int main()
{
	int mat[R][C] = 
    {
    	{-2, -2, -1, -2, -2, -2},
        {-2, -1,  1, -1, -2, -2},
        {-1,  1,  1,  1, -1, -2},
        {-1,  1,  1,  1,  1, -1},
        {-1, -1, -1, -1, -1, -2},
        {-2, -2, -2, -2, -2, -2},

    };
    int startRow = 0 ;
    int startCol = 2; // determined by the microprocessor

    findTotal(mat, countoftotal); // get the count of total right first 

    while (countoftotal > 0)
    {
        if(countoftotal == 1) // populate the last one unique graph that has only one left
        {
            populateLast(mat);
            countoftotal = countoftotal-1;
        }
   
     
        Go_Down_Path ( mat, row, col, Determine_Orientation ( mat, startRow, startCol ), countoftotal);

        if ( orientation == "down_right")
        {
            col = col + 1;
        }

      



        cout << Determine_Orientation( mat, row, col) ;
        cout << row;
        cout << col;

        if(Determine_Orientation( mat, row, col)  == "down_left")
        {
            cout << "here!!" << endl;
         	col = col -1 ;
        }
        cout<< row;
        cout << col;


        Go_Down_Path(mat, row, col,"down_left",countoftotal);
        cout<< row;
        cout << col <<endl;

    	cout<< CounterClock( mat, row, col); 
    	cout << "break" << endl;

        Go_Down_Path(mat, row, col,"left",countoftotal);


        col = col -1;
        cout << row;
        cout << col;

        cout << Determine_Orientation( mat, row, col) ;


        Go_Down_Path(mat, row, col,"up",countoftotal);

        row = row -1;
        cout << Determine_Orientation ( mat, row, col);

        Go_Down_Path(mat, row, col,"up_right", countoftotal);

        print(mat);

        if(countoftotal == 1) // populate the last one unique graph that has only one left
        {
            populateLast(mat);
            countoftotal = countoftotal-1;
        }
    

    }

    return 0;
}