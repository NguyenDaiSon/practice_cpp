#include <iostream>
#include <memory>
#include <cassert>
#include <string>

struct Song 
{
	std::string mName;
	std::string mArtist;
	
	Song(std::string const& name, std::string const& artist)
		: mName{name}
		, mArtist{artist}
	{

	}

	void operator()() const
	{
		std::cout << mName << " - " << mArtist << '\n';
	}
};

std::unique_ptr<Song> songFactory(std::string const& name, std::string const& artist)
{
	/// Implicit move semantic
	return std::make_unique<Song>(name, artist);
}

int main()
{
	auto song = songFactory("Nothing Else Matters", "Metallica");
	assert(song != nullptr);
	(*song)();
}
