{"filter":false,"title":"usuals.c","tooltip":"/src/usuals.c","undoManager":{"mark":30,"position":30,"stack":[[{"start":{"row":47,"column":0},"end":{"row":47,"column":29},"action":"remove","lines":["int\t\tinstr(char *str, char c)"],"id":2,"ignore":true}],[{"start":{"row":47,"column":0},"end":{"row":48,"column":0},"action":"remove","lines":["",""],"id":3,"ignore":true}],[{"start":{"row":47,"column":0},"end":{"row":50,"column":0},"action":"remove","lines":["{","\tint\ti;","",""],"id":4,"ignore":true}],[{"start":{"row":47,"column":0},"end":{"row":50,"column":0},"action":"remove","lines":["\ti = 0;","\twhile (str[i])","\t{",""],"id":5,"ignore":true}],[{"start":{"row":47,"column":0},"end":{"row":50,"column":2},"action":"remove","lines":["\t\tif (str[i] == c)","\t\t\treturn (1);","\t\ti++;","\t}"],"id":6,"ignore":true}],[{"start":{"row":47,"column":0},"end":{"row":49,"column":1},"action":"remove","lines":["","\treturn (0);","}"],"id":7,"ignore":true}],[{"start":{"row":46,"column":0},"end":{"row":47,"column":0},"action":"remove","lines":["",""],"id":8,"ignore":true}],[{"start":{"row":45,"column":1},"end":{"row":46,"column":0},"action":"remove","lines":["",""],"id":9,"ignore":true}],[{"start":{"row":45,"column":1},"end":{"row":46,"column":0},"action":"insert","lines":["",""],"id":10,"ignore":true}],[{"start":{"row":46,"column":0},"end":{"row":58,"column":1},"action":"insert","lines":["int\t\tinstr(char *str, char c)","{","\tint\ti;","","\ti = 0;","\twhile (str[i])","\t{","\t\tif (str[i] == c)","\t\t\treturn (1);","\t\ti++;","\t}","\treturn (0);","}"],"id":11,"ignore":true}],[{"start":{"row":14,"column":0},"end":{"row":16,"column":16},"action":"remove","lines":["void\tft_putstrsp(char *str)","{","\tft_putstr(str);"],"id":12,"ignore":true}],[{"start":{"row":14,"column":0},"end":{"row":16,"column":1},"action":"remove","lines":["","\tft_putstr(\"  \");","}"],"id":13,"ignore":true}],[{"start":{"row":13,"column":0},"end":{"row":14,"column":0},"action":"remove","lines":["",""],"id":14,"ignore":true}],[{"start":{"row":12,"column":18},"end":{"row":13,"column":0},"action":"remove","lines":["",""],"id":15,"ignore":true}],[{"start":{"row":31,"column":1},"end":{"row":33,"column":0},"action":"insert","lines":["","",""],"id":16,"ignore":true}],[{"start":{"row":33,"column":0},"end":{"row":37,"column":1},"action":"insert","lines":["void\tft_putstrsp(char *str)","{","\tft_putstr(str);","\tft_putstr(\"  \");","}"],"id":17,"ignore":true}],[{"start":{"row":36,"column":14},"end":{"row":37,"column":1},"action":"remove","lines":["\");","}"],"id":18,"ignore":true}],[{"start":{"row":36,"column":13},"end":{"row":36,"column":14},"action":"remove","lines":[" "],"id":19,"ignore":true}],[{"start":{"row":36,"column":4},"end":{"row":36,"column":13},"action":"remove","lines":["putstr(\" "],"id":20,"ignore":true}],[{"start":{"row":35,"column":15},"end":{"row":36,"column":4},"action":"remove","lines":[";","\tft_"],"id":21,"ignore":true}],[{"start":{"row":35,"column":9},"end":{"row":35,"column":15},"action":"remove","lines":["r(str)"],"id":22,"ignore":true}],[{"start":{"row":35,"column":3},"end":{"row":35,"column":9},"action":"remove","lines":["_putst"],"id":23,"ignore":true}],[{"start":{"row":35,"column":2},"end":{"row":35,"column":3},"action":"remove","lines":["t"],"id":24,"ignore":true}],[{"start":{"row":33,"column":26},"end":{"row":35,"column":2},"action":"remove","lines":[")","{","\tf"],"id":25,"ignore":true}],[{"start":{"row":33,"column":20},"end":{"row":33,"column":26},"action":"remove","lines":["r *str"],"id":26,"ignore":true}],[{"start":{"row":33,"column":14},"end":{"row":33,"column":20},"action":"remove","lines":["sp(cha"],"id":27,"ignore":true}],[{"start":{"row":33,"column":7},"end":{"row":33,"column":14},"action":"remove","lines":["_putstr"],"id":28,"ignore":true}],[{"start":{"row":33,"column":0},"end":{"row":33,"column":7},"action":"remove","lines":["void\tft"],"id":29,"ignore":true}],[{"start":{"row":32,"column":0},"end":{"row":33,"column":0},"action":"remove","lines":["",""],"id":30,"ignore":true}],[{"start":{"row":32,"column":0},"end":{"row":33,"column":0},"action":"insert","lines":["",""],"id":31,"ignore":true}],[{"start":{"row":33,"column":0},"end":{"row":59,"column":1},"action":"insert","lines":["char\t*add_path(char *p, char *n)","{","\tchar\t*new;","\tint\t\ti;","","\ti = 0;","\tnew = (char *)malloc(sizeof(*new) * (ft_strlen(p) + ft_strlen(n) + 2));","\tif (new == NULL)","\t\treturn (NULL);","\twhile (*p)","\t{","\t\tnew[i] = *p++;","\t\ti++;","\t}","\tif (new[i - 1] != '/')","\t{","\t\tnew[i] = '/';","\t\ti++;","\t}","\twhile (*n)","\t{","\t\tnew[i] = *n++;","\t\ti++;","\t}","\tnew[i] = '\\0';","\treturn (new);","}"],"id":32,"ignore":true}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":35,"column":11},"end":{"row":35,"column":11},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":7,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1450369955000,"hash":"31b5b92f5a7882f86fb6f3dca59222ee1d2e713e"}