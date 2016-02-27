#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

struct Player {
	int time_arrive;
	int time_play;

	Player(int time_arrive, int time_play): time_arrive(time_arrive), time_play(time_play > 120 ? 7200 : (time_play * 60)) {};
};

struct Table {
	int time_serve;
	int num_player;
	bool is_vip;

	Table(): time_serve(28800), num_player(0), is_vip(false) {};
};

bool compare(Player *a, Player *b) { return a->time_arrive < b->time_arrive; };

int main() {
	list<Player *> commons, vips;
	int num_player;
	scanf("%d", &num_player);
	for (int i = 0; i < num_player; i++) {
		int hour, minute, second, time_play, is_vip;
		scanf("%d:%d:%d %d %d", &hour, &minute, &second, &time_play, &is_vip);
		if (hour > 20)
			continue;
		Player *player = new Player(hour * 3600 + minute * 60 + second, time_play);
		if (is_vip > 0)
			vips.push_back(player);
		else
			commons.push_back(player);
	}
	commons.sort(compare);
	vips.sort(compare);
	int num_table, num_vip;
	scanf("%d %d", &num_table, &num_vip);
	Table *tables = new Table[num_table];
	for (int i = 0; i < num_vip; i++) {
		int idx;
		scanf("%d", &idx);
		tables[--idx].is_vip = true;
	}

	while (!commons.empty() || !vips.empty()) {
		int idx = 0;
		for (int i = 1; i < num_table; i++)
			if (tables[idx].time_serve > tables[i].time_serve)
				idx = i;
		if (tables[idx].time_serve >= 75600)
			break;

		Player *player;
		if (!vips.empty() && (tables[idx].is_vip && (tables[idx].time_serve >= vips.front()->time_arrive))) {
			player = vips.front();
			vips.pop_front();
		}
		else if (commons.empty() || (!vips.empty() && (vips.front()->time_arrive < commons.front()->time_arrive))) {
			player = vips.front();
			vips.pop_front();
			for (int i = 0; i < num_table; i++) {
				if (tables[i].is_vip && (tables[i].time_serve <= player->time_arrive)) {
					idx = i;
					break;
				}
			}
		}
		else {
			player = commons.front();
			commons.pop_front();
		}
		int time_arrive = player->time_arrive;
		int time_serve = tables[idx].time_serve > time_arrive ? tables[idx].time_serve : time_arrive;
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", time_arrive / 3600, (time_arrive % 3600) / 60, time_arrive % 60, time_serve / 3600, (time_serve % 3600) / 60, time_serve % 60, int((time_serve - time_arrive) / 60.0 + 0.5));
		tables[idx].time_serve = time_serve + player->time_play;
		tables[idx].num_player++;
		delete player;
	}
	printf("%d", tables[0].num_player);
	for (int i = 1; i < num_table; i++)
		printf(" %d", tables[i].num_player);

	return 0;
}