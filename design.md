
# Sequence diagram : main
```mermaid
sequenceDiagram
    CLI ->> main: main(input, output)
    main ->> Manager: «create»
    loop for inputs
    main ->> main: read a line
    main ->> Manager: processCommand(line)
    Manager -->> main: result
    main ->> main: write result to output
    end
    main ->> Manager: «destroy»

```

# Class diagram
```mermaid
classDiagram
    class Manager {
        -database: Database
        +processCommand(cmd_line: string) string
    }
    class CommandProcessor {
        +process(database: Database) string
    }
    class CommandFactory {
        +createProcessoFor(cmd_name: string) CommandProcessor
    }
    class InvalidCommandExeption 
    CommandFactory ..> CommandProcessor
    CommandFactory ..> InvalidCommandExeption: «throw»
    CommandProcessor ..> InvalidCommandExeption: «throw»
    Manager --> CommandFactory
    class Database {
        +insert()
        +delete()
        +update()
    }
    Manager --o Database
    Manager ..> CommandProcessor
```
 * Manager: 관리 시스템 메인, 명령어를 받아 CommandFactory로부터 CommandProcessor를 생성하여 실행한다.
 * CommandFactory: CommandProcessor 를 생성한다.
 * CommandProcessor: CommandXxx의 supper class.
 * InvalidCommandException: CommandProcessor에서 처리가 불가할 때 발생하는 오류

```mermaid
classDiagram
    class CommandProcessor {
        +process(database: Database) string
    }
    class CommandFactory {
        +createProcessoFor(cmd_name: string) CommandProcessor
    }
    class CommandAdd
    class CommandDel
    class CommandSch
    class CommandMod
    CommandFactory ..> CommandProcessor
    CommandAdd --|> CommandProcessor
    CommandDel --|> CommandProcessor
    CommandSch --|> CommandProcessor
    CommandMod --|> CommandProcessor
    CommandFactory ..> CommandAdd: «create»
    CommandFactory ..> CommandDel: «create»
    CommandFactory ..> CommandSch: «create»
    CommandFactory ..> CommandMod: «create»
```

```mermaid
classDiagram
    class Database {
        +insert()
        +delete()
        +update()
    }
    class MemoryDatabase
    class FileDatabase
    
    MemoryDatabase --|> Database
    FileDatabase --|> Database
```
