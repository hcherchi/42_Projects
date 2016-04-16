var i = 0;

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
	var list = document.getElementById('ft_list');
	var newdiv = document.createElement('div');
	newdiv.className = 'case';
	newdiv.innerHTML = txt;
	newdiv.id = i;
	list.insertBefore(newdiv, list.childNodes[0]);
	setCookie(i, txt, 1);
	i += 1;
	newdiv.addEventListener("click", function(eventObject)
	{
		var sure = confirm("Are you sure you want to delete this todo?");
		if (sure)
		{
			newdiv.parentNode.removeChild(newdiv);
			setCookie(newdiv.id, "bla", -1);
		}
	});
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
		elem[0] = elem[0].trim();
		if (elem[1] != undefined && elem[0][0] != '_')
			list.push(elem[1]);
		setCookie(elem[0], elem[1], -1);
	}
	for (var i = 0; i < list.length; i++)
	{
		addElem(list[i]);
	}
	i = list.length;
}