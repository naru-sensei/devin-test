#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define DEFAULT_GREETING "Hello, Naru Sensei!"
#define DEFAULT_NAME "Naru Sensei"
#define DEFAULT_REPETITIONS 56

typedef struct {
    char greeting[100];
    char name[100];
    int repetitions;
} Config;

void initConfig(Config *config) {
    strcpy(config->greeting, DEFAULT_GREETING);
    strcpy(config->name, DEFAULT_NAME);
    config->repetitions = DEFAULT_REPETITIONS;
}

void loadFromEnv(Config *config) {
    char *env_greeting = getenv("HELLO_GREETING");
    char *env_name = getenv("HELLO_NAME");
    char *env_repetitions = getenv("HELLO_REPETITIONS");
    
    if (env_greeting != NULL) {
        strncpy(config->greeting, env_greeting, sizeof(config->greeting) - 1);
        config->greeting[sizeof(config->greeting) - 1] = '\0';
    }
    
    if (env_name != NULL) {
        strncpy(config->name, env_name, sizeof(config->name) - 1);
        config->name[sizeof(config->name) - 1] = '\0';
    }
    
    if (env_repetitions != NULL) {
        int rep = atoi(env_repetitions);
        if (rep > 0) {
            config->repetitions = rep;
        } else {
            fprintf(stderr, "警告: 無効な繰り返し回数です。デフォルト値を使用します。\n");
        }
    }
}

void printUsage(const char *program_name) {
    printf("使用方法: %s [オプション]\n", program_name);
    printf("オプション:\n");
    printf("  -g, --greeting=TEXT   挨拶メッセージを設定 (デフォルト: \"%s\")\n", DEFAULT_GREETING);
    printf("  -n, --name=TEXT       表示する名前を設定 (デフォルト: \"%s\")\n", DEFAULT_NAME);
    printf("  -r, --repetitions=N   繰り返し回数を設定 (デフォルト: %d)\n", DEFAULT_REPETITIONS);
    printf("  -h, --help            このヘルプメッセージを表示\n");
    printf("\n");
    printf("環境変数:\n");
    printf("  HELLO_GREETING      挨拶メッセージを設定\n");
    printf("  HELLO_NAME          表示する名前を設定\n");
    printf("  HELLO_REPETITIONS   繰り返し回数を設定\n");
}

int parseArgs(int argc, char *argv[], Config *config) {
    static struct option long_options[] = {
        {"greeting", required_argument, 0, 'g'},
        {"name", required_argument, 0, 'n'},
        {"repetitions", required_argument, 0, 'r'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };
    
    int option_index = 0;
    int c;
    
    while ((c = getopt_long(argc, argv, "g:n:r:h", long_options, &option_index)) != -1) {
        switch (c) {
            case 'g':
                strncpy(config->greeting, optarg, sizeof(config->greeting) - 1);
                config->greeting[sizeof(config->greeting) - 1] = '\0';
                break;
            case 'n':
                strncpy(config->name, optarg, sizeof(config->name) - 1);
                config->name[sizeof(config->name) - 1] = '\0';
                break;
            case 'r': {
                int rep = atoi(optarg);
                if (rep > 0) {
                    config->repetitions = rep;
                } else {
                    fprintf(stderr, "エラー: 繰り返し回数は正の整数である必要があります。\n");
                    return 0;
                }
                break;
            }
            case 'h':
                printUsage(argv[0]);
                return 0;
            case '?':
                return 0;
            default:
                abort();
        }
    }
    
    return 1;
}

int main(int argc, char *argv[]) {
    Config config;
    
    initConfig(&config);
    
    loadFromEnv(&config);
    
    if (!parseArgs(argc, argv, &config)) {
        return 1;
    }
    
    printf("%s\n", config.greeting);
    
    for (int i = 0; i < config.repetitions; i++) {
        printf("%d: %s\n", i + 1, config.name);
    }
    
    return 0;
}
