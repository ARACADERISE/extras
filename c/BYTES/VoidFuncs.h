void CreateByte(int ofAmmount);
void checkName(const char *CheckFor);

// We want arguments to be a pre-processor directive so it isn't ran at runtime
#define PARSE_ARGS(ammount,arg) \
for(int i = 0; i < ammount;i++) {\
	if(!(strcmp(arg[i],"./main")==0)) {\
		/* Default: -file */\
		const char DefaultType[6]="-file";\
		if(strcmp(arg[i],"-makeByte")==0) {\
			if(arg[i+1]&&!(arg[i+1][0]=='-')) {\
				if(atoi(arg[i+1])==0&&!(arg[i+1][0]=='-')) {\
					printf("\033[3;31mAssigning default: bytes: 1, type: -file\n\033[0;0m");\
					CreateByte(8);\
					checkName(DefaultType);\
				} else {\
					CreateByte(atoi(arg[i+1]));\
					if(arg[i+2]) {\
						checkName(arg[i+2]);\
					} else {\
						checkName(DefaultType);\
					}\
				}\
			} else {\
				printf("\n\033[3;32mHOW TO USE \"-makeByte\":\nThe argument following -makeByte must be an integer of any size(depending on your system).\nThis number will be the bit size, thusly transformed into bytes\nAfter you have given it the ammount of bits you want, you need to specify what these bits(which are being transformed into bytes) are fore\nUse: -file, -integer, -string or -characters as you 3rd Command-Line-Argument(defaults to -file)\n-makeByte is usually used when a certain ammount of bytes is needed for function in C.\n\033[0;0mCREATING ONE BYTE..\n\n");\
				CreateByte(8);/*DEFAULT MAKING ONE BYTE*/\
				if(arg[i+1][0]=='-') checkName(arg[i+1]);\
			}\
		}\
	}\
}
