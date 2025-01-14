import matplotlib.pyplot as plt

# Fonction pour charger les données depuis un fichier
def charger_donnees_angles(fichier):
    data_sans_calibration = []
    data_750ms = []
    data_2000ms = []
    with open(fichier, 'r') as f:
        lines = f.readlines()
        is_750ms = False
        is_2000ms = False
        is_sans_calibration = False
        
        for line in lines:
            if "Sans Calibration" in line:
                is_sans_calibration = True
                is_750ms = False
                is_2000ms = False
            if "750 ms" in line:
                is_750ms = True
                is_2000ms = False
                is_sans_calibration = False
            elif "2000 ms" in line:
                is_2000ms = True
                is_750ms = False
                is_sans_calibration = False
            else:
                try:
                    # Extraction des données numériques
                    valeur = float(line.split(". ")[1])
                    if is_750ms:
                        data_750ms.append(valeur)
                    elif is_2000ms:
                        data_2000ms.append(valeur)
                    elif is_sans_calibration:
                        data_sans_calibration.append(valeur)
                except:
                    pass

    return data_sans_calibration, data_750ms, data_2000ms, 

def charger_donnees_distance(fichier):
    data_750ms = []
    data_2000ms = []
    
    with open(fichier, 'r', encoding='utf-16') as f:
        lines = f.readlines()
        is_750ms = False
        is_2000ms = False
        
        for line in lines:
            if "750 ms" in line:
                is_750ms = True
                is_2000ms = False
            elif "2000 ms" in line:
                is_2000ms = True
                is_750ms = False
            else:
                try:
                    # Extraction des données numériques après le point et espace
                    if is_750ms or is_2000ms:
                        valeur = float(line.split(". ")[1])
                        if is_750ms:
                            data_750ms.append(valeur)
                        elif is_2000ms:
                            data_2000ms.append(valeur)
                except:
                    pass  # Ignore les lignes qui ne contiennent pas de données numériques

    return data_750ms, data_2000ms







# Charger les données des deux fichiers
# fichier1 = 'data_brosse_dents.txt'
# fichier2 = 'data_exosquellette.txt'
fichier1 = 'dist_brosse_dents.txt'
fichier2 = 'dist_exosquellette.txt'

# data1_sans, data1_750ms, data1_2000ms = charger_donnees_angles(fichier1)
# data2_sans, data2_750ms, data2_2000ms = charger_donnees_angles(fichier2)

data1_750ms, data1_2000ms = charger_donnees_distance(fichier1)
data2_750ms, data2_2000ms = charger_donnees_distance(fichier2)

# Création du premier boxplot
plt.figure(figsize=(8, 5))
# plt.boxplot([data1_sans, data1_750ms, data1_2000ms], labels=['Sans calibration', '750 ms', '2000 ms'], patch_artist=True,
#             boxprops=dict(facecolor='lightblue', color='black'),
#             medianprops=dict(color='red'))
plt.boxplot([data1_750ms, data1_2000ms], labels=['750 ms', '2000 ms'], patch_artist=True,
            boxprops=dict(facecolor='lightblue', color='black'),
            medianprops=dict(color='red'))
#plt.title("Comparaison des angles de déviation par rapport au temps de calibration dans le modèle avec brosse à dents")
plt.title("Comparaison des distances parcourues par rapport au temps de calibration dans le modèle avec brosse à dents")
#plt.ylabel("Angles de déviation (°)")
plt.ylabel("Distance (cm)")
plt.xlabel("Durée")
plt.show()

# Création du deuxième boxplot
plt.figure(figsize=(8, 5))
# plt.boxplot([data2_sans, data2_750ms, data2_2000ms], labels=['Sans calibration', '750 ms', '2000 ms'], patch_artist=True,
#             boxprops=dict(facecolor='lightgreen', color='black'),
#             medianprops=dict(color='red'))
plt.boxplot([data2_750ms, data2_2000ms], labels=['750 ms', '2000 ms'], patch_artist=True,
            boxprops=dict(facecolor='lightgreen', color='black'),
            medianprops=dict(color='red'))
#plt.title("Comparaison des angles de déviation par rapport au temps de calibration avec l'exosquelette")
plt.title("Comparaison des distances parcourues par rapport au temps de calibration avec l'exosquelette")
#plt.ylabel("Angles de déviation (°)")
plt.ylabel("Distance (cm)")
plt.xlabel("Durée")
plt.show()
