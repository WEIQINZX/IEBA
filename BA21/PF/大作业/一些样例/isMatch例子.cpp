bool isMatch(string word,string target){
	int i=0;  //i用来记录走到了word的第几个字符 
	int j=0; //j记录的是匹配上的字符数（而且是从前往后数的，如果有一个匹配不上，那就一直停留在它的位置） 
	int last=0;  //
	int star=-1; //用来表示目前的star的位置的 
	
	while(i<word.size()){ //只要还没走到 word的结尾 
		if(j<target.size() && ((word[i]==target[j]) ||target[j]=='.' )){ //target没结束，且word和target相应的字符相等ORtarget里面这个字指的是.（这种情况也可以对应上） 
			i++; //表示对应上了，word走向下一个词 
			j++; //target开始检索下一个字 
			continue; //跳过后面的所有内容，看下一个字 
		}else if (j< target.size() && target[j]=='*'){  //target没结束且target里出现*
			last=i; //记录一下在word中查到哪儿了 
			star=j++; //记录下*在taarget中的位置star，再检索下一个字 
		}else if(star!=-1){ //有*存在 
			i=++last; //last++，再令i=last 
			j=star+1; //开始检索star的下一个字 
		}else{
			return false;
		}
	}
	
	while(j<target.size() && target[j]=='*'){
		j++;
	}
	
	return j==target.size();
} 
