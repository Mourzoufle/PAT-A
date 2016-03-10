#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

struct Player {
	int time_arrive;																											// arriving time
	int time_play;																												// playing time

	Player(int time_arrive, int time_play): time_arrive(time_arrive), time_play(time_play > 120 ? 7200 : (time_play * 60)) {};	// no player can play more than 2 hour (7200 seconds)
};

struct Table {
	int time_serve;																												// time that this table is available
	int num_player;																												// number of pairs of players playing at this table
	bool is_vip;

	Table(): time_serve(28800), num_player(0), is_vip(false) {};																// club opens at 8:00
};

/* compare fuction for sorting players - by the arriving time */
bool cmp(Player *a, Player *b) { return a->time_arrive < b->time_arrive; };

int main() {
	list<Player *> commons, vips;																								// common and VIP players
	int num_player;
	scanf("%d", &num_player);
	for (int i = 0; i < num_player; i++) {
		int hour, minute, second, time_play, is_vip;
		scanf("%d:%d:%d %d %d", &hour, &minute, &second, &time_play, &is_vip);
		if (hour > 20)																											// players coming no earlier than 21:00 are ignored
			continue;
		Player *player = new Player(hour * 3600 + minute * 60 + second, time_play);
		if (is_vip > 0)
			vips.push_back(player);
		else
			commons.push_back(player);
	}
	commons.sort(cmp);
	vips.sort(cmp);
	int num_table, num_vip;																										// total number of tables; number of VIP tables
	scanf("%d %d", &num_table, &num_vip);
	Table *tables = new Table[num_table];
	for (int i = 0; i < num_vip; i++) {
		int idx;																												// index of VIP table (start from 1)
		scanf("%d", &idx);
		tables[--idx].is_vip = true;
	}

	while (!commons.empty() || !vips.empty()) {
		int cur_table = 0;																										// the first table that is available
		for (int i = 1; i < num_table; i++)
			if (tables[cur_table].time_serve > tables[i].time_serve)
				cur_table = i;
		if (tables[cur_table].time_serve >= 75600)																				// no table is available earlier than 21:00, the remaining players cannot get served
			break;

		Player *cur_player;
		if (!vips.empty() && (tables[cur_table].is_vip && (tables[cur_table].time_serve >= vips.front()->time_arrive))) {		// the table is for VIP players, and there exist VIP players before it is available - VIP players get it
			cur_player = vips.front();
			vips.pop_front();
		}
		else if (commons.empty() || (!vips.empty() && (vips.front()->time_arrive < commons.front()->time_arrive))) {			// or it is turn for VIP players
			cur_player = vips.front();
			vips.pop_front();
			for (int i = 0; i < num_table; i++) {																				// if there exists a VIP table available before they come, then they will play at this table
				if (tables[i].is_vip && (tables[i].time_serve <= cur_player->time_arrive)) {
					cur_table = i;
					break;
				}
			}
		}
		else {																													// or it is turn for common players
			cur_player = commons.front();
			commons.pop_front();
		}
		int time_arrive = cur_player->time_arrive;
		int time_serve = tables[cur_table].time_serve > time_arrive ? tables[cur_table].time_serve : time_arrive;				// game begins when both players and the table are ready 
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", time_arrive / 3600, (time_arrive % 3600) / 60, time_arrive % 60, time_serve / 3600, (time_serve % 3600) / 60, time_serve % 60, int((time_serve - time_arrive) / 60.0 + 0.5));
		tables[cur_table].time_serve = time_serve + cur_player->time_play;
		tables[cur_table].num_player++;
		delete cur_player;
	}
	printf("%d", tables[0].num_player);
	for (int i = 1; i < num_table; i++)
		printf(" %d", tables[i].num_player);

	return 0;
}