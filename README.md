# Chess-Client
Lightweight, terminal-based chess client

See the server or the GUI client repos for more information...

# Communication b/w server and client
- Entirely text-based via ASIO sockets. Server maintains the gamestate, and sends the board state to the client each turn to poll for his/her turn.
