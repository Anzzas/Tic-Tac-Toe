#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:

	Player(char sign)
		: m_sign{ sign }
	{
	}

	virtual ~Player() = default;

	const char& getSign() const;

protected:

	const char m_sign;
};

#endif