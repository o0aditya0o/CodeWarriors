void validmoves(int a[13][13],int valid[13][13],int player)
{
	for(int i=1;i<13;i++)
		for(int j=1;j<13;j++)
		if(a[i][j]==player)
 			{
 				int count=0;
 				for (int k = i-1;k>=0; --k)//Checks for up direction
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

 				for (int k = i+1;k<12; ++k)//Checks for down direction
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

 				for (int k = j+1;k<12; ++k)//Checks for right direction
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

 				for (int k = j-1;k>=0; --k)//Checks for left direction
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

 				for (int k = j-1,l=i-1;k>=0&&l>=0; --k,--l)//Checks for up-left direction
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

 				for (int k = j+1,l=i-1;k<12&&l>=0; ++k,--l)//Checks for up-right direction
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

 				for (int k = j+1, l=i+1;k<12&&l<12; ++k,++l)//Checks for down-right direction
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

 				for (int k = j-1, l=i+1; k>=0 && l<12 ; --k,++l)//Checks for down-left direction
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
 	
