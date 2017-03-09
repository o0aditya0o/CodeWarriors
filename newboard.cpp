void newboard(int a[][],int b[][],int x,int y,int player)
{

 				for (int k = x-1;k>0; --k)//Checks for up direction
 				{
 					if(a[k][j]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[k][j]==0)//there must be a valid move as x...0->this is the position i can place my player
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
 					if(a[k][j]==reverse(player))
 						++count;
 					else
 					{
 						if(count>0 && a[k][j]==0)//there must be a valid move as x...0->this is the position i can place my player
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
 						if(count>0 && a[i][k]==0)//there must be a valid move as x...0->this is the position i can place my player
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