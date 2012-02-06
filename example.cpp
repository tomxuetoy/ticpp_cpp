class Fruit {public: void peel(); void slice(); void juice();
			Fruit(int i, int j);
			~Fruit();
			private: int weight, calories_per_oz;
			};

Fruit::Fruit(int i, int j) {weight = i; calories_per_oz = j;}
Fruit::~Fruit() {}

main()
{
	Fruit melon(4, 5), banana(12, 8);
}
