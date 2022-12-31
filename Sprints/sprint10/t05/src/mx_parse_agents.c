#include "../inc/header.h"

void without_arg(int argc, char *argv[]) {
	if (argc != 3 || mx_strlen(argv[1]) > 2) {
		mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
		exit(-1);
	}
}

int mx_count_agent(char *s) {
	int s_len = mx_strlen(s);
	char agent[] = "agent";
	int agent_len = mx_strlen(agent);
	int result = 0;
	int number = 0;
	int k = 0;
	for (int i = 0; i < s_len; ) {
		k = 0;
		number = 0;
		while (s[i] == agent[k]) {
			number++;
			i++;
			k++;
		}
		if (number == agent_len) {
			result += 1;
			number = 0;
		}
		else {
			i++;
		}
	}
	return result;
}


int sort_name(t_agent *agent1, t_agent *agent2) {
	if (mx_strcmp(agent1->name, agent2->name) < 0) {
		return 1;
	}
	return 0;
}

int sort_power(t_agent *agent1, t_agent *agent2) {
	if (agent1->power < agent2->power) {
		return 1;
	}
	return 0;
}

int sort_strength(t_agent *agent1, t_agent *agent2) {
	if (agent1->strength < agent2->strength) {
		return 1;
	}
	return 0;
}
 
void sort_all(t_agent **agents, int (*compare)(t_agent*, t_agent*), int count) {
	int number = 1;
	t_agent *agent = malloc(sizeof(t_agent*));
	while (number) {
		number = 0;
		for (int i = 1; i < count; i++) {
			if (compare(agents[i], agents[i - 1])) {
				agent = agents[i];
				agents[i] = agents[i - 1];
				agents[i - 1] = agent;
				number = 1;
			}
		}
	}
}
				

void sort_result(char *argv[], t_agent **agents, int count) {
	switch (argv[1][1]) {
		case 'n':
			sort_all(agents, sort_name, count);
			break;
		case 'p':
			sort_all(agents, sort_power, count);
			break;
		case 's':
			sort_all(agents, sort_strength, count);
			break;
		default: 
			mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
            exit(-1);
	}
}  

void print_result(t_agent **agents, int count) {
	for (int i = 0; i < count; i++) {
		mx_printstr("agent: ");
        mx_printstr(agents[i]->name);
        mx_printstr(", strength: ");
        mx_printint(agents[i]->strength);
        mx_printstr(", power: ");
        mx_printint(agents[i]->power);
        mx_printchar('\n');
	}
}

int main(int argc, char *argv[]) {
	without_arg(argc, argv);
	char *s = mx_file_to_str(argv[2]);
	int count = mx_count_agent(s);
	t_agent **agents = (t_agent**)malloc(count * sizeof(t_agent*));
	for (int i = 0; i < count; i++) {
		agents[i] = (t_agent*)malloc(count * sizeof(t_agent));
	}
	char example1[] = "agent {\n\tname: ";
    char example2[] = "\tpower: ";
    char example3[] = "\tstrength: ";
    char example4[] = "}\n";
    char *arr_name;
    for (int i = 0; i < count; i++) {
    	for (int  j = 0; j < mx_strlen(example1); j++) {
			if (*s != example1[j]) {
				mx_printerr("error\n");
				exit(-1);
			}
			s++;
		}
    	int ind = 0;
    	arr_name = malloc(60);
    	while (*s != '\n') {
    		arr_name[ind] = *s;
    		s++;
    		ind++;
    	}
    	agents[i]->name = arr_name;
    	agents[i]->name[ind] = '\0';
    	s++;
    	for (int  j = 0; j < mx_strlen(example2); j++) {
			if (*s != example2[j]) {
				mx_printerr("error\n");
				exit(-1);
			}
			s++;
		}
    	agents[i]->power = mx_atoi(s);
    	int digit = agents[i]->power;
    	while (digit > 0) {
    		digit /= 10;
    		s++;
    	}
    	s++;
    	for (int  j = 0; j < mx_strlen(example3); j++) {
			if (*s != example3[j]) {
				mx_printerr("error\n");
				exit(-1);
			}
			s++;
		}
    	agents[i]->strength = mx_atoi(s);
    	digit = agents[i]->strength;
    	while (digit > 0) {
    		digit /= 10;
    		s++;
    	}
    	s++;
    	for (int  j = 0; j < mx_strlen(example4); j++) {
			if (*s != example4[j]) {
				mx_printerr("error\n");
				exit(-1);
			}
			s++;
		}
    	ind = 0;
   }
   sort_result(argv, agents, count);
   print_result(agents, count);
   free(arr_name);
   free(s);
   free(*agents);
   free(agents);
   exit(0);    	 
}

		
