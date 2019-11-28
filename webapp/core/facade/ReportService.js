(function() {
  'use strict';

  const Filter = require("./Filter");
  const {Connection} = require('../../core/utility/connection');

  const ReportService = module.exports = {};

  ReportService.findAnaliseData = async function(params) {

    const conn = new Connection("postgis://mpmt:secreto@terrama2.dpi.inpe.br:5432/mpmt");
    await conn.connect();

    const view = JSON.parse(params.view);

    const table = {
      name: await Filter.getTableName(conn, view.id),
      alias: 'main_table',
      owner: ''
    };

    const filter =  await Filter.setFilter(conn, params, table, view);

    let sqlWhere = filter.sqlWhere;

    const select =
        ` SELECT  ${table.alias}.*
                  , ST_Y(ST_Transform (ST_Centroid(${table.alias}.intersection_geom), 4326)) AS "lat"
                  , ST_X(ST_Transform (ST_Centroid(${table.alias}.intersection_geom), 4326)) AS "long"
        `;

    const from = ` FROM public.${table.name} AS ${table.alias} `;

    const sql =
      `
        ${select}
        ${from}
        ${filter.secondaryTables}
        ${filter.sqlWhere}
        ${filter.order}
        ${filter.limit}
        ${filter.offset}
      `;

    let result;
    let resultCount;
    try {
      result = await conn.execute(sql);
      let dataJson = result.rows;


      if (params.countTotal) {
        const sqlCount =
            ` SELECT COUNT(*) AS count FROM public.${table.name} AS ${table.alias}
              ${filter.secondaryTables}
              ${filter.sqlWhere}
            `;
        resultCount = await conn.execute(sqlCount);
        dataJson.push(resultCount.rows[0]['count']);
      }

      await conn.disconnect();
      return dataJson;
    } catch (error) {
      console.log(error);
      return [];
    }
  };

} ());
