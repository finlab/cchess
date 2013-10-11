#pragma once

class MyFace
{
public:
	unsigned char red[16];
	unsigned char black[16];
	int next;

public:
	MyFace(void);
	~MyFace(void);

	int evaluate();
	bool issame(MyFace& f);
};



