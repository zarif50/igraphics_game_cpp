char Enemynumber[3][20]={"enemy\\1.png","enemy\\2.png","enemy\\3.png"};
struct enemy{
	int enemy_x;
	int enemy_y;
	int ind;
	bool enemy_show;
};
struct enemy enemy_no[3];

int enemy_pos=0;

void enemy_set(){
	for(int i=0;i<3;i++){
		enemy_no[i].enemy_show=true;
		enemy_no[i].enemy_x=screenwidth-200;
		enemy_no[i].enemy_y=screenheight + rand() % 300;
		enemy_pos=i;
		iloadImage(
	}
}

