bool isMatch(string word,string target){
	int i=0;  //i������¼�ߵ���word�ĵڼ����ַ� 
	int j=0; //j��¼����ƥ���ϵ��ַ����������Ǵ�ǰ�������ģ������һ��ƥ�䲻�ϣ��Ǿ�һֱͣ��������λ�ã� 
	int last=0;  //
	int star=-1; //������ʾĿǰ��star��λ�õ� 
	
	while(i<word.size()){ //ֻҪ��û�ߵ� word�Ľ�β 
		if(j<target.size() && ((word[i]==target[j]) ||target[j]=='.' )){ //targetû��������word��target��Ӧ���ַ����ORtarget���������ָ����.���������Ҳ���Զ�Ӧ�ϣ� 
			i++; //��ʾ��Ӧ���ˣ�word������һ���� 
			j++; //target��ʼ������һ���� 
			continue; //����������������ݣ�����һ���� 
		}else if (j< target.size() && target[j]=='*'){  //targetû������target�����*
			last=i; //��¼һ����word�в鵽�Ķ��� 
			star=j++; //��¼��*��taarget�е�λ��star���ټ�����һ���� 
		}else if(star!=-1){ //��*���� 
			i=++last; //last++������i=last 
			j=star+1; //��ʼ����star����һ���� 
		}else{
			return false;
		}
	}
	
	while(j<target.size() && target[j]=='*'){
		j++;
	}
	
	return j==target.size();
} 
