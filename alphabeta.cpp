function alphabeta(node, depth, α, β, maximizingPlayer)
02      if depth = 0 or node is a terminal node
03          return the heuristic value of node
04      if maximizingPlayer
05          v := -∞
06          for each child of node
07              v := max(v, alphabeta(child, depth - 1, α, β, FALSE))
08              α := max(α, v)
09              if β ≤ α
10                  break (* β cut-off *)
11          return v
12      else
13          v := ∞
14          for each child of node
15              v := min(v, alphabeta(child, depth - 1, α, β, TRUE))
16              β := min(β, v)
17              if β ≤ α
18                  break (* α cut-off *)
19          return v

int alphabeta(int a[][],int depth,int a,int b,int player)
	{
		int v,c=0,moves[13][13];
		validmoves(a,moves,player);
		for(i=1;i<13;i++)
			for(j=1;j<13;j++)
				if(moves[i][j]==1)
					c++;

		if(depth==0 || c==0)
		{
			return score(a,player);
		}
		if(player==maximizing)//Define a global variable maximizing and set it equal to num
		{
			v=-INFINITY;
			for(i=1;i<13;i++)
			{
				for(j=1;j<13;j++)
				{
					if(moves[i][j]==1)
					{
						int child[13][13];
						copy(a,child);
						newboard(a,child,i,j,player);
						v=max(v,alphabeta(child,depth-1,a,b,reverse(player)));
						a=max(a,v);
						if(b<=a)
							return v;
					}
				}
			}
		}
		else
		{
			v=INFINITY;
			for(i=1;i<13;i++)
			{
				for(j=1;j<13;j++)
				{
					if(moves[i][j]==1)
					{
						int child[13][13]=newboard(a,i,j,player);
						v=min(v,alphabeta(child,depth-1,a,b,reverse(player)));
						b=min(b,v);
						if(b<=a)
							return v;
					}
				}
			}
		}
	}