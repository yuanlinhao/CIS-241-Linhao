
#!/bin/bash



# The overall most powerfull Pokemon
cat Pokemon.csv | awk -F, '
BEGIN{
	max=0;
	sum=0;
	maxname="";
}
{
	if (NR==1) next;
	for(i=6;i<=11;i++) sum+=$i;
	if(sum>max) {
		max=sum;
		maxname=$2
	}
	sum=0;
}
END{
	printf "Most powerfull Pokemon is: "
	printf maxname;
	printf " with total value "
	print max;
}'




# The average of each column for the entire file
cat Pokemon.csv | awk -F, '
BEGIN{}
{
	if (NR==1) next;
	for (i=6;i<=11;i++) sum[i]+=$i;
}
END{
	print "Average of each column: "
	for (i=6;i<=11;i++) {
		printf sum[i]/NR; 
		if (i<11) printf ",";
		}
	print "";
}'





# The most powerful Pokemon for each type
cat Pokemon.csv | awk -F, '
BEGIN{
	name[6]="HP";
	name[7]="Attack";
	name[8]="Defense";
	name[9]="SP Atk";
	name[10]="SP Def";
	name[11]="Speed";
}
{
	if (NR==1) next;
	for (i=6;i<=11;i++) {
		if ($i>max[i]) {
			max[i]=$i;
			maxname[i]=$2;
		}
	}	
}
END{
	print "The most powerful Pokemon for each type: "
	for (i=6;i<=11;i++) {
		printf name[i];
		if (i<11) printf ",";
		}
	print "";
	for (i=6;i<=11;i++) {
		printf maxname[i];
		if (i<11) printf ",";
		}
	print "";
}'








