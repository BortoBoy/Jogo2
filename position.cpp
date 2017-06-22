class Position{
	public:
		int x;
		int y;
		
		Position(int, int);
		Position();
};

Position :: Position(int x, int y){
	this->x = x;
	this->y = y;
}
Position :: Position(){
	this->x = 0;
	this->y = 0;	
}
