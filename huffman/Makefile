object := HuffMan_Table_Generate HuffMan_Decode HuffMan_Code

table:
	@gcc -o HuffMan_Table_Generate  HuffMan_Table_Generate.c
	@./HuffMan_Table_Generate

encode:
	@gcc -o HuffMan_Code  HuffMan_Code.c
	@./HuffMan_Code

decode:
	@gcc -o HuffMan_Decode  HuffMan_Decode.c
	@./HuffMan_Decode


clean:
	rm  $(object) *.txt
