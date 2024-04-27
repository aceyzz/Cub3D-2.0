# Plusieurs types d'éléments :

## [ `A` ]
> EXEMPLE: `[A]		[0.2]	 [255,255,255]`
- lumière ambiante
- ses 2 paramètres:
	- [ `0.2` ]			1 nombre flottant, désigne le ratio de l'intensité compris entre 0.0 et 1.0
	- [ 255,255,255 ]	3 nombres entiers, couleurs RGB (de 0 a 255)

---

## [ `C` ]
> EXEMPLE : `[C]	[-50.0, 0.0, 20.0]		[0.0, 0.0, 1.0]		[70]`
- Camera
- ses 3 paramètres"
	- [ `-50.0 , 0.0 , 20.0 `]	3 nombres flottants, désignes les coordonées du point de vue				// x, y, z
	- [ `0.0, 0.0, 1.0` ]		3 nombres flottants, désigne l'orientation du vecteur entre -1 et 1			// x, y, z
	- [ `70` ]					1 nombre entier, champs de vision (nommé FOV) entre 0 et 180

---

## [ `L` ]
> EXEMPLE: `[L]	[-40.0, 50.0, 0.0]	[0.6]	[10,0,255]`
- Lumière
- ses 3 paramètres:
	- [ `-40.0, 50.0, 0.0` ]	3 nombres flottants, désignent les coordonnées du point lumineux			// x, y, z
	- [ `0.6` ]					1 nombre flottant, désigne le ratio de l'intensité lumineuse entre 0.0 et 1.0
	- [ `10, 0, 255` ]			3 nombres entiers, couleurs RGB (de 0 à 255)

---

## [ `sp` ]
> EXEMPLE: `[sp]	[0.0,0.0,20.6]	[12.6]	[10,0,255]`
- Sphere (Sphère)
- ses 3 paramètres:
	- [ `0.0, 0.0, 20.6` ]		3 nombres flottants, désignent les coordonnées du centre de la sphère	// x, y, z
	- [ `12.6` ]				1 nombre flottant, désigne le diamètre de la sphère
	- [ `10, 0, 255` ]			3 nombres entiers, couleurs RGB (de 0 à 255)

---

## [ `pl` ]
> EXEMPLE: `[pl]	[0.0,0.0,-10.0]	[0.0,1.0,0.0]	[0,0,225]`
- Plan (ou Plane)
- ses 3 paramètres:
	- [ `0.0, 0.0, -10.0` ]		3 nombres flottants, désignent les coordonnées d'un point sur le plan			// x, y, z
	- [ `0.0, 1.0, 0.0` ]		3 nombres flottants, désigne le vecteur normal du plan, normalisé entre -1 et 1	// x, y, z
	- [ `0, 0, 225` ]			3 nombres entiers, couleurs RGB (de 0 à 255)

---

## [ `cy` ]
> EXEMPLE: `[cy]	[50.0,0.0,20.6]	[0.0,0.0,1.0]	[14.2]	[21.42]	[10,0,255]`
- Cylindre
- ses 5 paramètres:
	- [ `50.0, 0.0, 20.6` ]		3 nombres flottants, désignent les coordonnées du centre du cylindre			// x, y, z
	- [ `0.0, 0.0, 1.0` ]		3 nombres flottants, désigne le vecteur d'axe du cylindre, normalisé entre -1 et 1	// x, y, z
	- [ `14.2` ]				1 nombre flottant, désigne le diamètre du cylindre
	- [ `21.42` ]				1 nombre flottant, désigne la hauteur du cylindre
	- [ `10, 0, 255` ]			3 nombres entiers, couleurs RGB (de 0 à 255)

---
