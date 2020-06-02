#include "TestData.h"
#include "balancedArray.h"

int main(void)
{
	
	srand(time(NULL));
		
	minitest();

	ofstream output;

	output.open("OutputData-BST.csv");

	output << "N,log_2(N),Sorted,Balanced,Scrambled #0,Scrambled #1,Scrambled #2,Scrambled #3,Scrambled #4" << endl;

	int i = 0, height = 0;
	
	BST sorted, balanced, s0, s1, s2, s3, s4;

	output << i << ',' << log2(i) <<  sorted.maxHeight() << ',' << balanced.maxHeight() << ',' << s0.maxHeight() << ',' << s1.maxHeight() << s2.maxHeight() << ',' << s3.maxHeight() <<  ',' << s4.maxHeight() << endl; 

	while (i < 5000)
	{
		output << i + 1 << ',';
		
		output << log2(i + 1) << ',';

		sorted.insert(i);
		height = sorted.maxHeight();
		output << height << ',';
		
		balanced.insert(balancedArray[i]);
		height = balanced.maxHeight();
		output << height << ',';

		s0.insert(randomNumber());
		height = s0.maxHeight();
		output << height << ',';

		s1.insert(randomNumber());
		height = s1.maxHeight();
		output << height << ',';

		s2.insert(randomNumber());
		height = s2.maxHeight();
		output << height << ',';

		s3.insert(randomNumber());
		height = s3.maxHeight();
		output << height << ',';

		s4.insert(randomNumber());
		height = s4.maxHeight();
		output << height << endl;

		i++;
	}		


	output.close();
}

