void MergeSort(long long a[],long long lo,long long hi){
	if(hi-lo<2)
		return;
	long long mi=(lo+hi)>>1;
	MergeSort(a,lo,mi);
	MergeSort(a,mi,hi);
	Merge(a,lo,mi,hi); 
}

void Merge(long long a[],long long lo,long long mi,long long hi){
	long long *b=new long long[hi-lo];
	long long index=0;
	long long i=lo;
	long long j=mi;
	while((i<mi) &&(j<hi)){
		if(a[i]<a[j])
			b[index++]=a[i++];
		else
			b[index++]=a[j++];
	}
	while(j<hi)
		b[index++]=a[j++];
	for(long long k=lo;k<hi;k++)
		a[k]=b[k-lo];
	delete b;
	return;
}
