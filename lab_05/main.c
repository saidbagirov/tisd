#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
#include "constants.h"

int main(void)
{
	int type;
	setbuf(stdout, NULL);
	printf("1.Массив/2.Список: ");
	scanf("%d", &type);
	if (type == 1)
	{
		automat *a;
		queue_t *q1 = new_queue(ELEM);
		a = init_auto();
		int len1 = 0, j = 1;
		float stay1 = 0, t = 0, i = 0;
		double duration = 0;
		clock_t t1, t2;
		srand((unsigned int) time(NULL));
		printf("МОДЕЛИРОВАНИЕ\n");
		while (a->diferent_elems < TIME)
		{
			t1 = clock();
			t = get_time(q1, a);
			t2 = clock();
			if (!t)
				return 0;
			duration = duration + (double) (t2 - t1) / CLOCKS_PER_SEC;
			if (!(a->diferent_elems % MOD) && i != a->diferent_elems)
			{
				i = a->diferent_elems;
				len1 += q1->num_of_elems;
				stay1 += q1->data_store[q1->front-1];
				printf("ПРОМЕЖУТОЧНОЕ\n\n");
				printf("Текущее время: %28.3f\n", t);
				printf("Количество ушедших из очереди: %12d\n", a->left1);
				j++;
				printf("Длина очереди: %28d\n", q1->num_of_elems);
				printf("Средняя длина очереди:  %19d\n", len1 / j);
				printf("Среднее время простоя очереди:  %11.6f\n\n", stay1 / j);
			}
		}
		double t1min = T1_MIN, t1max = T1_MAX, t2min = T2_MIN, t2max = T2_MAX;
		double av_t_in1 = (t1min + t1max) / 2, av_t_out1 = (t2min + t2max) / 2;
		//printf("%lf %lf\n", av_t_in1, av_t_out1);
		double total_t_in1 = TIME * av_t_in1;
		double total_t_out1 = TIME * av_t_out1;
		//double total_out = total_t_out1 + total_t_out2, t_modelling1;
		printf("Среднее время прихода: %f\n"
			"Среднее время обработки: %f\n"
			"Расчётное время моделирования: %.3f\n"
			"Расчётное время моделирования работы ОА: %.3f\n", av_t_in1, av_t_out1, total_t_in1, total_t_out1);
		printf("\n\nИТОГОВЫЙ РЕЗУЛЬТАТ\n\n"
			"Время моделирования: %32f\n"
			"Время работы ОА: %36f\n"
			"Время простоя: %38f\n"
			"Количество выведенных различных заявок: %13d\n"
			"Количество заявок, введённых в очередь: %13d\n"
			"Количество обработанных заявок из очереди:%11d\n\n", t, a->work, a->downtime, a->diferent_elems, q1->summ_of_elems, a->left1);
		double error1 = fabs(((a->diferent_elems - t / av_t_in1) / t / av_t_in1) * 100);
		double error2 = fabs(((t - a->work - a->downtime) / (a->work + a->downtime)) * 100);
		printf("Процент различия оценочных изменений и реальных по входу: %lf%%.\n", error1);
		printf("Процент различия оценочных изменений и реальных по выходу: %lf%%.\n", error2);
		printf("Погрешность работы системы: %lf%%.\n\n", error1 + error2);
		queue_free(q1);
		return 0;
	}
	else if (type == 2)
	{
		automat_list *a;
		srand((unsigned int) time(NULL));
		queue_t_list *q1 = init_queue_list();
		a = init_auto_list();
		int len1 = 0, j = 1;
		float stay1 = 0, t = 0, i = 0;
		double duration = 0;
		clock_t t1, t2;

		printf("МОДЕЛИРОВАНИЕ\n\n");
		while (a->diferent_elems < TIME)
		{
			t1 = clock();
			t = get_time_list(q1, a);
			t2 = clock();
			if (!t)
				return 0;
			duration = duration + (double) (t2 - t1) / CLOCKS_PER_SEC;

			if (!(a->diferent_elems % MOD) && i != a->diferent_elems)
			{
				i = a->diferent_elems;
				len1 += q1->num_of_elems;
				stay1 += q1->pout->time;
				printf("ПРОМЕЖУТОЧНОЕ\n\n");
				printf("Текущее время: %28.3f\n", t);
				printf("Количество ушедших из очереди: %12d\n", a->left1);
				j++;
				printf("Длина очереди: %28d\n", q1->num_of_elems);
				printf("Средняя длина очереди:  %19d\n", len1 / j);
				printf("Среднее время простоя очереди:  %11.6f\n\n", stay1 / j);
			}
		}
		double t1min = T1_MIN, t1max = T1_MAX, t2min = T2_MIN, t2max = T2_MAX;
		double av_t_in1 = (t1min + t1max) / 2, av_t_out1 = (t2min + t2max) / 2;

		//printf("%lf %lf\n", av_t_in1, av_t_out1);
		double total_t_in1 = TIME * av_t_in1;
		double total_t_out1 = TIME * av_t_out1;
		//double total_out = total_t_out1 + total_t_out2, t_modelling1;


		printf("Среднее время прихода: %f\n"
			"Среднее время обработки: %f\n"
			"Расчётное время моделирования: %.3f\n"
			"Расчётное время моделирования работы ОА: %.3f\n\n",
			av_t_in1, av_t_out1, total_t_in1, total_t_out1);

		printf("\n\nИТОГОВЫЙ РЕЗУЛЬТАТ\n"
			"Время моделирования: %32f\n"
			"Время работы ОА: %36f\n"
			"Время простоя: %38f\n"
			"Количество выведенных различных заявок: %13d\n"
			"Количество заявок, введённых в очередь: %13d\n"
			"Количество обработанных заявок из очереди:%11d\n\n", t, a->work, a->downtime, a->diferent_elems, q1->summ_of_elems, a->left1);

		double error1 = fabs(((a->diferent_elems - t / av_t_in1) / t / av_t_in1) * 100);
		double error2 = fabs(((t - a->work - a->downtime) / (a->work + a->downtime)) * 100);
		printf("Процент различия оценочных изменений и реальных по входу: %lf %%.\n", error1);
		printf("Процент различия оценочных изменений и реальных по выходу: %lf %%.\n", error2);
		printf("Погрешность работы системы: %lf %%.\n\n", error1 + error2);

		//free_queue_list(q1);
		return 0;
	}
}