var i = 0;
var list = $('#ft_list');
var bouton = $('#add');

bouton.on('click', getTxt);

function getTxt()
{
	var txt = prompt('What do you want me to remind you ?');
	if (txt && txt != '')
	{
		addElem(txt);
	}
}

function addElem(txt)
{
	var name = '#' + i;
	list.prepend('<div class="case" id="' + i + '">' + txt + '</div>');
	setCookie('#' + i, txt, 1);
	$(name).on("click", function()
		{
			if (confirm("Are you sure you want to delete this todo?"));
			{
				$(name).remove();
				setCookie(name, "bla", -1);
			}
		});
	i++;
}

function setCookie(name, value, hours)
{
	var today = new Date(), expires = new Date();
        expires.setTime(today.getTime() + (60*60*1000 * hours));
    document.cookie = name + '=' + value+ ";expires=" + expires.toGMTString();
}

function getCookies()
{
	var x = document.cookie;
	var list = new Array();
	var cooks = x.split(";");
	for (var i = 0; i < cooks.length; i++)
	{
		var elem = cooks[i].split("=");
		if (elem[1] != undefined)
			list.push(elem[1]);
		setCookie(elem[0], elem[1], -1);
	}
	for (var i = 0; i < list.length; i++)
	{
		addElem(list[i]);
	}
	i = list.length;
}