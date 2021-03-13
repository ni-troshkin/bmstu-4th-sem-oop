#include "processing.h"
#include "model_cdio.h"
#include "transform.h"

/*
 *
 * Распределение функций по модулям
 * Уровни абстракции отследить
 * Не больше трех переменных
 * Названия файлов и функций
 * Обработка ошибок в интерфейсе ----------
 * Строки в интерфейсе (память)  ----------
 * Заголовочные файлы (интерфейс или реализация)
 * Расположение in out var в списке параметров
 * Модификаторы const и ссылки проверить
 *
*/

model_t &process(const args_t &args)
{
    static model_t model = init_model();

    switch (args.action)
    {
        case EXIT: {
            model.error = delete_model(model);
            break;
        }
        case LOAD: {
            model.error = read_model(args.name, model);
            break;
        }
        case SAVE: {
            model.error = write_model(args.name, model);
            break;
        }
        case MOVE: {
            model.error = move(model, args.x, args.y, args.z);
            break;
        }
        case SCALE: {
            model.error = scale(model, args.x, args.y, args.z);
            break;
        }
        case ROTATE: {
            model.error = rotate(model, args.x, args.y, args.z);
            break;
        }
        default: {
            model.error = INVALID_FUNC;
            break;
        }
    }

    return model;
}
