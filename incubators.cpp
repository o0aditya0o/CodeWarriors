//------------------------CODE WARRIORS------------------------------------//
//-------------------------INCUBATORS-------------------------------------//
//-------------------------CODE TO WIN-------------------------------------//

#include<bits/stdc++.h>
#define INFINIT 99999999

using namespace std;

int maximizing;

int reverse(int num);
void validmoves(int a[13][13],int valid[13][13],int player);
void newboard(int a[13][13],int b[13][13],int x,int y,int player);
int alphabeta(int a[13][13],int depth,int al,int b,int player);

void copy(int a[13][13],int b[13][13]);

int main(){
 	int ansx,ansy,p=0,i,j,num,input[13][13],play[13][13]={0},score[1213]={0};
 	scanf("%d",&num);
 	maximizing=num;
 	for(i=1;i<13;i++)
 		for(j=1;j<13;j++)
 			scanf("%d",&input[i][j]);
 	validmoves(input,play,num);
 	for(i=1;i<13;i++)
 		for(j=1;j<13;j++)
 		{
 			if(play[i][j]==1)
 				score[i*100+j]=alphabeta(input,4,-INFINIT,+INFINIT,num);
 		}
 	sort(score,score+1213);
 	for(i=1212;i>0;i--)
 		if(score[i])
 		{
 			ansx=i/100;
 			ansy=i%100;
 		}
 		printf("%c%c",64+ansx,64+ansy);
 		return 0;


}

int reverse(int num){
	if(num==1)
		return 2;
	return 1;
}


void validmoves(int a[13][13],int valid[13][13],int player)
{
	for(int i=1;i<13;i++)
		for(int j=1;j<13;j++)
		if(a[i][j]==player)
 			{
 				int i,k,l,count=0;
 				for (k = i-1;k>=0; --k)//Checks for up direction
 				{
 					if(a[k][j]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[k][j]==0)//there must be a valid move as x...0->this is the position i can place my player
 							valid[k][j]=1;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}
 				count=0;

 				for (k = i+1;k<12; ++k)//Checks for down direction
 				{
 					if(a[k][j]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[k][j]==0)//there must be a valid move as x...0->this is the position i can place my player
 							valid[k][j]=1;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (k = j+1;k<12; ++k)//Checks for right direction
 				{
 					if(a[i][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[i][k]==0)//there must be a valid move as x...0->this is the position i can place my player
 							valid[i][k]=1;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (k = j-1;k>=0; --k)//Checks for left direction
 				{
 					if(a[i][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[i][k]==0)//there must be a valid move as x...0->this is the position i can place my player
 							valid[i][k]=1;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (k = j-1,l=i-1;k>=0&&l>=0; --k,--l)//Checks for up-left direction
 				{
 					if(a[l][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[l][k]==0)//there must be a valid move as x...0->this is the position i can place my player
 							valid[l][k]=1;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (k = j+1,l=i-1;k<12&&l>=0; ++k,--l)//Checks for up-right direction
 				{
 					if(a[l][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[l][k]==0)//there must be a valid move as x...0->this is a valid move
 							valid[l][k]=1;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (k = j+1, l=i+1;k<12&&l<12; ++k,++l)//Checks for down-right direction
 				{
 					if(a[l][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[l][k]==0)//there must be a valid move as x...0->this is a valid move
 							valid[l][k]=1;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (k = j-1, l=i+1; k>=0 && l<12 ; --k,++l)//Checks for down-left direction
 				{
 					if(a[l][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[l][k]==0)//there must be a valid move as x...0->this is a valid move
 							valid[l][k]=1;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 			}
 	}
 	

void newboard(int a[13][13],int b[13][13],int x,int y,int player)
{
				int count=0;
 				for (int k = x-1;k>0; --k)//Checks for up direction
 				{
 					if(a[k][y]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[k][y]==0)//there must be a valid move as x...0->this is the position i can place my player
 							for(k=x-1;k>=x-count;k--)
 								b[k][y]=player;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}
 				count=0;

 				for (int k = x+1;k<=12; ++k)//Checks for down direction
 				{
 					if(a[k][y]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[k][y]==0)//there must be a valid move as x...0->this is the position i can place my player
 							for(k=x+1;k<=x+count;k++)
 								b[k][y]=player;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (int k = y+1;k<=12; ++k)//Checks for right direction
 				{
 					if(a[x][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[x][k]==0)//there must be a valid move as x...0->this is the position i can place my player
 							for(k=y+1;k<=y+count;k++)
 								b[x][k]=player;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (int k = y-1;k>0; --k)//Checks for left direction
 				{
 					if(a[x][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[x][k]==0)//there must be a valid move as x...0->this is the position i can place my player
 							for(k=y-1;k>=y-count;k--)
 								b[x][k]=player;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (int k=y-1,l=x-1;k>0&&l>0; --k,--l)//Checks for up-left direction
 				{
 					if(a[l][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[l][k]==0)//there must be a valid move as x...0->this is the position i can place my player
 							for(k=y-1,l=x-1;k>=y-count&&l>=x-count;k--,l--)
 								b[l][k]=player;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (int k = y+1,l=x-1;k<=12&&l>0; ++k,--l)//Checks for up-right direction
 				{
 					if(a[l][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[l][k]==0)//there must be a valid move as x...0->this is a valid move
 							for(k=y+1,l=x-1;k<=y+count&&l>=x-count;k++,l--)
 								b[l][k]=player;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (int k = y+1, l=x+1;k<=12&&l<=12; ++k,++l)//Checks for down-right direction
 				{
 					if(a[l][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[l][k]==0)//there must be a valid move as x...0->this is a valid move
 							for(k=y+1,l=x+1;k<=y+count&&l<=x+count;k++,l++)
 								b[l][k]=player;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}

 				count=0;

 				for (int k = y-1, l=x+1; k>0 && l<=12 ; --k,++l)//Checks for down-left direction
 				{
 					if(a[l][k]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[l][k]==0)//there must be a valid move as x...0->this is a valid move
 							for(k=y-1,l=x+1;k>=y-count&&l<=x+count;k--,l++)
 								b[l][k]=player;
 						break;
 					}
 					if(count==0)
 						break;//No valid move here
 				}
 	}
 	int heuristic(int a[13][13],int player)
 		{
 			int ans=0;
 			for (int i = 1; i <13; ++i)
 			{
 				for (int j = 1; j <13; ++j)
 				{
 					if(a[i][j]==player)
 						ans++;
 					else if(a[i][j]=reverse(player))
 						ans--;
  				}
 			}
 			return ans;
 		}

 	int alphabeta(int a[13][13],int depth,int al,int b,int player)
	{
		int i,j,v,c=0,moves[13][13];
		validmoves(a,moves,player);
		for(i=1;i<13;i++)
			for(j=1;j<13;j++)
				if(moves[i][j]==1)
					c++;

		if(depth==0 || c==0)
		{
			return heuristic(a,player);
		}
		if(player==maximizing)//Define a global variable maximizing and set it equal to num
		{
			v=-INFINIT;
			for(i=1;i<13;i++)
			{
				for(j=1;j<13;j++)
				{
					if(moves[i][j]==1)
					{
						int child[13][13];
						copy(a,child);
						newboard(a,child,i,j,player);
						v=max(v,alphabeta(child,depth-1,al,b,reverse(player)));
						al=max(al,v);
						if(b<=al)
							return v;
					}
				}
			}
		}
		else
		{
			v=INFINIT;
			for(i=1;i<13;i++)
			{
				for(j=1;j<13;j++)
				{
					if(moves[i][j]==1)
					{
						int child[13][13];
						newboard(a,child,i,j,player);
						v=min(v,alphabeta(child,depth-1,al,b,reverse(player)));
						b=min(b,v);
						if(b<=al)
							return v;
					}
				}
			}
		}
	}

	void copy(int a[13][13],int b[13][13])
	{
		for (int i = 1; i < 13; ++i)
		{
			for (int j=1; j< 13; ++j)
			{
				b[i][j]=a[i][j];
			}
		}
	}
