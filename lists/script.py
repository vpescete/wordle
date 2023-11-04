# Apri il file di input in modalità lettura
with open('parole_4.txt', 'r') as input_file:
    # Leggi il contenuto del file riga per riga
    lines = input_file.readlines()

# Apri il file di output in modalità scrittura
with open('parole_4_ord.txt', 'w') as output_file:
    # Per ogni riga nel file di input
    for line in lines:
        # Suddividi la riga in parole utilizzando gli spazi come delimitatori
        words = line.split()
        
        # Scrivi le parole una sotto l'altra nel file di output
        for word in words:
            output_file.write(word + '\n')
