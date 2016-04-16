#!/usr/bin/php
<?PHP
    while (1)
    {
        print("Entrez un nombre: ");
        if (($nb = trim(fgets(STDIN))) == NULL)
        {
            print("$nb\n");
            break;
        }
        if (is_numeric($nb))
        {
            print("Le chiffre $nb ");
            if ($nb % 2 == 0)
                print(" est Pair\n");
            else
                print(" est Impair\n");
        }
        else
        {
            print("'$nb' n'est pas un chiffre\n");
        }
    }
?>
